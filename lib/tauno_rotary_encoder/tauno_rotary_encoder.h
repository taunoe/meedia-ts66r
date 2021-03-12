/*
 * File         tauno_rotary_encoder.h
 * Last edited  12.03.2021
 * 
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 */

#ifndef LIB_TAUNO_ROTARY_ENCODER_TAUNO_ROTARY_ENCODER_H_
#define LIB_TAUNO_ROTARY_ENCODER_TAUNO_ROTARY_ENCODER_H_

#include <Arduino.h>

class Tauno_Rotary_Encoder {

 private:
  uint8_t new_SW_PIN;
  uint8_t new_CLK_PIN;
  uint8_t new_DT_PIN;

 public:
  Tauno_Rotary_Encoder(
    uint8_t SW_PIN,
    uint8_t CLK_PIN,
    uint8_t DT_PIN);

  // Destructor
  ~Tauno_Rotary_Encoder();

  void say_pins();

  uint8_t get_turn();

};


#endif  // LIB_TAUNO_ROTARY_ENCODER_TAUNO_ROTARY_ENCODER_H_
