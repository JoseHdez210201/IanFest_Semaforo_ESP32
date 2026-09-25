#include <Arduino.h>

#define LED_PIN 2 // Pin del LED integrado en la mayoría de placas genéricas

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("ESP32 inicializado correctamente.");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}