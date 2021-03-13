/*
 * File         tauno_rotary_encoder.cpp
 * Last edited  13.03.2021
 * 
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 */

#include <Arduino.h>
#include "tauno_rotary_encoder.h"

// Constructor
Tauno_Rotary_Encoder::Tauno_Rotary_Encoder(
    uint8_t SW_PIN,
    uint8_t CLK_PIN,
    uint8_t DT_PIN)
    : new_SW_PIN(SW_PIN),
      new_CLK_PIN(CLK_PIN),
      new_DT_PIN(DT_PIN),
      _counter(0),    // Running count of encoder clicks
      _last_time(0),  // Last time read click
      _period(600),   // Velocity calculation period
      _last_speed(0)  // Last calculated speed (no sign) in clicks/second
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
 * 255 == DIR_CCW - Counterclockwise
 *   1 == DIR_CW  - Clockwise
 *   0 == DIR_NONE
 **/
uint8_t Tauno_Rotary_Encoder::read() {
  /**
   * The static keyword is used to create variables that are visible to only one function. 
   * However unlike local variables that get created and destroyed every time a function is called, 
   * static variables persist beyond the function call, preserving their data between function calls.
   * Variables declared as static will only be created and initialized the first time a function is called. 
   **/
  static uint8_t old_a = 0;
  static uint8_t old_b = 0;

  uint8_t status = 0;
  uint8_t new_a = digitalRead(new_CLK_PIN);
  uint8_t new_b = digitalRead(new_DT_PIN);

  // If the value of CLK pin or the DT pin has changed
  if (new_a != old_a || new_b != old_b) {
    if (old_a == 1 && new_a == 0) {
      status = (old_b * 2 - 1);
    }
  }

  old_a = new_a;
  old_b = new_b;

  count_clicks(status);
  count_speed();

  return status;
}


/*
 *  Counts rotary encoder clicks.
 */
void Tauno_Rotary_Encoder::count_clicks(uint8_t status) {
  if (status != 0) {
    _counter++;
  }
}


/*
 *  Calculates speed
 */
void Tauno_Rotary_Encoder::count_speed() {
  if (millis() - _last_time >= _period) {
    // speed = ClickCount * (1000 / period)
    _last_speed = _counter * (1000 / _period);
    _last_time = millis();
    _counter = 0;
  }
}


/*
 *  Retuns speed
 */
uint16_t Tauno_Rotary_Encoder::speed() {
  return _last_speed;
}
