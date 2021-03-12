/*
 * File         debug.h
 * Last edited  12.03.2021
 * 
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 */

// Enable debug info serial print
#ifndef TAUNO_DEBUG_H_
#define TAUNO_DEBUG_H_

  #define DEBUG_PRINT(x)  Serial.print(x)
  #define DEBUG_PRINTLN(x)  Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)

#endif  // TAUNO_DEBUG_H_
