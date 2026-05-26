#include <SPI.h>
#include <LoRa.h>

#define ss 18
#define rst 14
#define dio0 26

#define BUTTON1 32

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON1, INPUT_PULLUP);

  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Failed");
    while (1);
  }

  Serial.println("LoRa TX Ready");
}

void loop() {

  if (digitalRead(BUTTON1) == LOW) {

    LoRa.beginPacket();
    LoRa.print("HAZARD ALERT");
    LoRa.endPacket();

    Serial.println("Alert Sent");

    delay(1000);
  }
}
