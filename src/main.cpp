/*
 * File      main.cpp
 * Projeckt  Media Dial
 * Board     Arduino Pro Micro 5v/16Mhz
 * Hardware  Rotary encoder, Pixel Ring 12 x RGB LED
 * Edited    23.03.2021
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 * 
 * 
 */
#include <Arduino.h>
#include <Keyboard.h>
// https://github.com/arduino-libraries/Keyboard
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Mouse.h>
// https://github.com/arduino-libraries/Mouse
// https://www.arduino.cc/reference/en/language/functions/usb/mouse/

//#define DEBUG

#include "tauno_debug.h"
#include "tauno_rotary_encoder.h"
#include <Adafruit_NeoPixel.h>

// LEDs pin
const uint8_t LEDS_PIN = 8;
const uint8_t LEDS_NUM = 12;

const uint8_t loop_interval = 500;

Adafruit_NeoPixel pixels(LEDS_NUM, LEDS_PIN, NEO_GRB + NEO_KHZ800);

// Rotary Encoder pins
const int RE_SW_PIN  = 2;
const int RE_CLK_PIN = 5;
const int RE_DT_PIN  = 6;

Tauno_Rotary_Encoder rotary_encoder(RE_SW_PIN, RE_CLK_PIN, RE_DT_PIN);

/*
 *
 */
void pixels_routine(uint8_t delay) {
  static uint32_t _prev_millis = 0;
  static uint8_t _i = 0;

  if ((millis() - _prev_millis) >= delay) {
    pixels.clear();

    if (_i < LEDS_NUM) {
      DEBUG_PRINT(" prev_millis=");
      DEBUG_PRINTLN(_prev_millis);
      pixels.setPixelColor(_i, pixels.Color(150, 0, 0));
      pixels.show();
      _prev_millis = millis();
      _i++;
    }

    if (_i == LEDS_NUM) {
      _i = 0;
    }
  }
}


void setup() {
  Serial.begin(9600);

  rotary_encoder.begin();

  pixels.begin();
}

void loop() {
  pixels_routine(loop_interval);

  int r = rotary_encoder.read();
  uint16_t s = rotary_encoder.speed();

  if (r == DIR_CW) {
    // Keyboard.write('z');

    DEBUG_PRINT(">");
    DEBUG_PRINTLN(s);

    #ifndef DEBUG
      // Mouse.move(0, 0, 1);

      do {
        Mouse.move(0, 0, 1);
        if (s > 0) {
          --s;
        }
      } while (s > 0);

    #endif

  } else if (r == DIR_CCW) {
    // Keyboard.write('k');

    DEBUG_PRINT("<");
    DEBUG_PRINTLN(s);

    #ifndef DEBUG
      // Mouse.move(0, 0, -1);
      do {
        Mouse.move(0, 0, -1);
        if (s > 0) {
          --s;
        }
      } while (s > 0);

    #endif
  }

  int b = rotary_encoder.button();
  if (b) {
    Serial.print("Button");
  }
}
