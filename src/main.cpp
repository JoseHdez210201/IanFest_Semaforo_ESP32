#include <Arduino.h>

// Definimos los pines de salida digital
#define RELAY_1_PIN 25 // Verde
#define RELAY_2_PIN 26 // Amarillo
#define RELAY_3_PIN 27 // Rojo

// Declaración de prototipo de funciones
void secuencia();
void verde();
void verde_parpadea();
void amarillo();
void rojo();

// Se configuran los pines como salida Open Drain, cuando mandas un HIGH en lugar de sacar 3.3V
// el ESP32 simplemente "desconecta" el pin (lo deja en alta impedancia).
void setup() {
  pinMode(RELAY_1_PIN, OUTPUT_OPEN_DRAIN);
  pinMode(RELAY_2_PIN, OUTPUT_OPEN_DRAIN);
  pinMode(RELAY_3_PIN, OUTPUT_OPEN_DRAIN);
}

// Se ejecuta de forma concurrente
void loop() {
  secuencia();
}

void secuencia(){
  verde();
  delay(5000);
  verde_parpadea();
  amarillo();
  delay(5000);
  rojo();
  delay(5000);
}

void verde(){
  digitalWrite(RELAY_1_PIN, LOW);
  digitalWrite(RELAY_2_PIN, HIGH);
  digitalWrite(RELAY_3_PIN, HIGH);
}

void verde_parpadea(){
  for (int i=0; i<4; i++) {
    digitalWrite(RELAY_1_PIN, LOW);
    delay(500);
    digitalWrite(RELAY_1_PIN, HIGH);
    delay(500);
  }
}

void amarillo(){
  digitalWrite(RELAY_1_PIN, HIGH);
  digitalWrite(RELAY_2_PIN, LOW);
  digitalWrite(RELAY_3_PIN, HIGH);
}

void rojo(){
  digitalWrite(RELAY_1_PIN, HIGH);
  digitalWrite(RELAY_2_PIN, HIGH);
  digitalWrite(RELAY_3_PIN, LOW);
}