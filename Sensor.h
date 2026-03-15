/*
 * Copyright 2026 Anderson Andino
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef Sensor_h
#define Sensor_h

#include <Arduino.h>

// ========== PINES SENSOR HY-S301 ==========
#define SENSOR_D1 A0
#define SENSOR_D2 A1
#define SENSOR_D3 A2
#define SENSOR_D4 A3
#define SENSOR_D5 A4
#define SENSOR_D6 A5
#define SENSOR_D7 11
#define SENSOR_D8 12

// ========== TIEMPO CALIBRACION ==========
#define T_CALIBRACION 10000

// ========== PINES LEDS ==========
#define LED_ROJO 2
#define LED_VERDE 3

class Sensor {
public:
  Sensor();
  void leer(uint8_t valores[8]);
  void calibrar();

private:
  uint8_t _pins[8];
};

#endif
