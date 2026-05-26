#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define ss 18
#define rst 14
#define dio0 26

#define BUZZER 25
#define LED 2

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire);

void setup() {

  Serial.begin(115200);

  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  display.begin(0x3C, true);
  display.clearDisplay();

  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Failed");
    while (1);
  }

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
  display.println("Receiver Ready");
  display.display();
}

void loop() {

  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    String message = "";

    while (LoRa.available()) {
      message += (char)LoRa.read();
    }

    Serial.println(message);

    display.clearDisplay();
    display.setCursor(0,0);
    display.println("WARNING!");
    display.println(message);
    display.display();

    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);

    delay(2000);

    digitalWrite(LED, LOW);
    noTone(BUZZER);
  }
}
