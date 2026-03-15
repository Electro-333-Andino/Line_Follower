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

#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

// ========== PINES L298N ==========
#define ENA 9
#define IN1 7
#define IN2 6
#define ENB 10
#define IN3 5
#define IN4 4

class Motor {
public:
  Motor();
  void avanzar(uint8_t velocidadIzquierda, uint8_t velocidadDerecha);
  void detener();

private:
  // No hay miembros privados necesarios por ahora
};

#endif
