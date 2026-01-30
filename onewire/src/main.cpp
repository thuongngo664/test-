#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
  Serial.println("DS18B20 start");
}

void loop() {
  sensors.requestTemperatures();
  float t = sensors.getTempCByIndex(0);
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println(" C");
  delay(1000);
}
