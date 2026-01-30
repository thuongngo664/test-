#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL
  Serial.println("I2C Scanner");
}

void loop() {
  int found = 0;
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.printf("Found: 0x%02X\n", addr);
      found++;
    }
  }
  if (!found) Serial.println("No I2C devices");
  Serial.println("----");
  delay(2000);
}
