#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4        // GPIO nối DATA
#define DHTTYPE DHT11   // loại cảm biến

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(500);

  dht.begin();
  Serial.println("DHT11 start...");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();      // Celsius
  float f = dht.readTemperature(true);  // Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT11!");
  } else {
    Serial.print("độ ẩm: ");
    Serial.print(h);
    Serial.print(" %\t");

    Serial.print("Nhiệt độ: ");
    Serial.print(t);
    Serial.print(" *C\t");

  }

  delay(2000); // DHT11 cần đọc chậm (~1-2s)
}
