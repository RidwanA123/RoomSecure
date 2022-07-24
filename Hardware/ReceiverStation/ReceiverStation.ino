
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 9); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
    pinMode(LED_BUILTIN, OUTPUT);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    tone(3,500,200);
      digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    noTone(3);
      digitalWrite(LED_BUILTIN, LOW);
  }
}
