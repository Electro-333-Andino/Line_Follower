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

#include <Arduino.h>
#include "Sensor.h"
#include "Motor.h"

// ========== VELOCIDADES ==========
#define VEL_BASE_IZQ 200
#define VEL_BASE_DER 170
#define VEL_CURVA_IZQ 120
#define VEL_CURVA_DER 100
#define VEL_GIRO_IZQ 100
#define VEL_GIRO_DER 80

// Instancias de las clases
Sensor sensor;
Motor motor;

void setup() {
  Serial.begin(9600);

  motor.detener();
  sensor.calibrar();

  Serial.println(F("
Listo! Esperando..."));

  for (uint8_t i = 4; i > 0; i--) {
    Serial.println(i);
    delay(1000);
  }

  Serial.println(F("
INICIANDO!
"));
}

void loop() {
  uint8_t sensores[8];
  sensor.leer(sensores);

  uint8_t enNegro = 0;
  for (uint8_t i = 0; i < 8; i++) {
    Serial.print(sensores[i]);
    Serial.print(' ');
    if (sensores[i]) enNegro++;
  }

  Serial.print(F("| N:"));
  Serial.print(enNegro);

  int8_t pos = calcularPosicion(sensores);

  if (pos == -100) {
    motor.detener();
    Serial.println(F(" PERDIDA"));
  } else {
    seguirLinea(pos);
    Serial.print(F(" P:"));
    Serial.println(pos);
  }

  delay(10);
}

int8_t calcularPosicion(uint8_t s[8]) {
  int8_t pesos[8] = {-7, -5, -3, -1, 1, 3, 5, 7};
  int8_t suma = 0;
  uint8_t count = 0;

  for (uint8_t i = 0; i < 8; i++) {
    if (s[i]) {
      suma += pesos[i];
      count++;
    }
  }

  if (count == 0) return -100;
  return suma / count;
}

void seguirLinea(int8_t pos) {
  uint8_t vIzq, vDer;

  if (pos >= -1 && pos <= 1) {
    // Línea centrada - RECTO
    vIzq = VEL_BASE_IZQ;
    vDer = VEL_BASE_DER;
  } else if (pos < -3) {
    // Línea MUY a la IZQUIERDA - girar IZQUIERDA
    vIzq = VEL_GIRO_IZQ;
    vDer = VEL_BASE_DER;
  } else if (pos < 0) {
    // Línea a la IZQUIERDA - curva IZQUIERDA
    vIzq = VEL_CURVA_IZQ;
    vDer = VEL_BASE_DER;
  } else if (pos > 3) {
    // Línea MUY a la DERECHA - girar DERECHA
    vIzq = VEL_BASE_IZQ;
    vDer = VEL_GIRO_DER;
  } else {
    // Línea a la DERECHA - curva DERECHA
    vIzq = VEL_BASE_IZQ;
    vDer = VEL_CURVA_DER;
  }

  motor.avanzar(vIzq, vDer);
}
