/*
 * File         tauno_rotary_encoder.cpp
 * Last edited  12.03.2021
 * 
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 */

#include <Arduino.h>
#include "tauno_rotary_encoder.h"

Tauno_Rotary_Encoder::Tauno_Rotary_Encoder(
    uint8_t SW_PIN,
    uint8_t CLK_PIN,
    uint8_t DT_PIN)
    : new_SW_PIN(SW_PIN),
      new_CLK_PIN(CLK_PIN),
      new_DT_PIN(DT_PIN)
    {}

// Destructor
Tauno_Rotary_Encoder::~Tauno_Rotary_Encoder() {
  Serial.print("Tauno Rotary Encoder Destructor!");
}

void Tauno_Rotary_Encoder::say_pins() {
  Serial.print("SW_PIN: ");
  Serial.print(new_SW_PIN);
  Serial.print(" CLK_PIN: ");
  Serial.print(new_CLK_PIN);
  Serial.print(" DT_PIN: ");
  Serial.println(new_DT_PIN);
}

/**
 * Reads rotary encoder turn direction
 * Returns:
 * 255 == Right to Left turn
 *   1 == Left to Right turn
 *   0 == No turn
 **/
uint8_t Tauno_Rotary_Encoder::get_turn() {
  /**
   * The static keyword is used to create variables that are visible to only one function. 
   * However unlike local variables that get created and destroyed every time a function is called, 
   * static variables persist beyond the function call, preserving their data between function calls.
   * Variables declared as static will only be created and initialized the first time a function is called. 
   **/
  static uint8_t old_a = 0;
  static uint8_t old_b = 0;
  uint8_t result = 0;
  uint8_t new_a = digitalRead(new_CLK_PIN);
  uint8_t new_b = digitalRead(new_DT_PIN);

  // If the value of CLK pin or the DT pin has changed
  if (new_a != old_a || new_b != old_b) {
    if (old_a == 1 && new_a == 0) {
      result = (old_b * 2 - 1);
    }
  }

  old_a = new_a;
  old_b = new_b;

  return result;
}
