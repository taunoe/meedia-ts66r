/*
 * File      main.cpp
 * Projeckt  Media Dial
 * Board     Arduino Pro Micro 5v/16Mhz
 * Hardware  Rotary encoder, Pixel Ring 12 x RGB LED
 * Edited    11.03.2021
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 * 
 * 
 */
#include <Arduino.h>
#include <Keyboard.h>
#include <Mouse.h>

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

  int a = rotary_encoder.get_turn();
  if (a == 1) {
    // Serial.println(a);
    // Keyboard.write('z');
    Mouse.move(0, 0, 1);
  } else if (a == 255) {
    // Keyboard.write('k');
    Mouse.move(0, 0, -1);
  }
  
}
