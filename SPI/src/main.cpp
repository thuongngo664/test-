#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

static const uint8_t SS_PIN  = 5;   // SDA/SS on RC522
static const uint8_t RST_PIN = 22;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void printUidHex(MFRC522::Uid *uid) {
  Serial.print("UID (HEX): ");
  for (byte i = 0; i < uid->size; i++) {
    if (uid->uidByte[i] < 0x10) Serial.print("0");
    Serial.print(uid->uidByte[i], HEX);
    if (i != uid->size - 1) Serial.print(":");
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  delay(200);

  SPI.begin(18, 19, 23, SS_PIN);   // SCK, MISO, MOSI, SS (VSPI default pins)
  mfrc522.PCD_Init();              // init RC522
  delay(50);

  Serial.println("RC522 ready. Hay cham the vao reader...");
}

void loop() {
  // Có thẻ mới chưa?
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  // Đọc UID
  if (!mfrc522.PICC_ReadCardSerial()) return;

  printUidHex(&mfrc522.uid);

  // Kết thúc phiên làm việc với thẻ để đọc tiếp thẻ khác
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  delay(300);
}
