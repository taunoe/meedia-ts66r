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

const int RXLED = 17;

void setup() {
  pinMode(RXLED, OUTPUT);
}

void loop() {
  digitalWrite(RXLED, HIGH);
  TXLED1;
  delay(500);

  digitalWrite(RXLED, LOW);
  TXLED0;
  delay(500);
}
