#include <Arduino.h>
#include <SPI.h>

#define CS_PIN 5

void setup() {
  Serial.begin(115200);
  SPI.begin(18, 19, 23, CS_PIN); // SCK, MISO, MOSI, SS
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  Serial.println("SPI ready");
}

uint8_t xfer(uint8_t v) {
  digitalWrite(CS_PIN, LOW);
  uint8_t r = SPI.transfer(v);
  digitalWrite(CS_PIN, HIGH);
  return r;
}

void loop() {
  uint8_t r = xfer(0xAA);
  Serial.printf("SPI RX: 0x%02X\n", r);
  delay(1000);
}
