/*
 * File      main.cpp
 * Projeckt  Media Dial
 * Board     Arduino Pro Micro 5v/16Mhz
 * Hardware  Rotary encoder, Pixel Ring 12 x RGB LED
 * Edited    13.03.2021
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

#include "tauno_debug.h"
#include "tauno_rotary_encoder.h"

// Rotary Encoder pins
const int RE_SW_PIN  = 2;
const int RE_CLK_PIN = 6;
const int RE_DT_PIN  = 5;

Tauno_Rotary_Encoder rotary_encoder(RE_SW_PIN, RE_CLK_PIN, RE_DT_PIN);


const int RXLED = 17;

void setup() {
  Serial.begin(9600);

  pinMode(RXLED, OUTPUT);
}

void loop() {
  /*digitalWrite(RXLED, HIGH);
  TXLED1;
  delay(500);

  digitalWrite(RXLED, LOW);
  TXLED0;
  delay(500);*/

  int a = rotary_encoder.read();
  uint16_t s = rotary_encoder.speed();

  if (a == DIR_CW) {
    Serial.print(">");
    // Keyboard.write('z');
    Serial.println(s);
    // Mouse.move(0, 0, 1);
  } else if (a == DIR_CCW) {
    Serial.print("<");
    // Keyboard.write('k');
    Serial.println(s);
    // Mouse.move(0, 0, -1);
  }
}
/*
inline void setPeriod(uint16_t t) {
  uint16_t  _period;  // velocity calculation period
  if ((t != 0) && (t <= 1000)) {
    _period = t;
  }
}*/
