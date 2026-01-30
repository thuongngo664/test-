#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define SDA_PIN 21
#define SCL_PIN 22

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  delay(200);

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!mpu.begin(0x68, &Wire)) { // đổi 0x69 nếu AD0 = HIGH
    Serial.println("❌ Không tìm thấy MPU6050");
    while (1) delay(10);
  }
  Serial.println("✅ MPU6050 connected");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t acc, gyro, temp;
  mpu.getEvent(&acc, &gyro, &temp);

  Serial.printf(
    "ACC: %.2f %.2f %.2f | GYRO: %.2f %.2f %.2f | T: %.2f C\n",
    acc.acceleration.x, acc.acceleration.y, acc.acceleration.z,
    gyro.gyro.x, gyro.gyro.y, gyro.gyro.z,
    temp.temperature
  );

  delay(200);
}
