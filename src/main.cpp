#include <Arduino.h>
#include <Network.h>
#include <State.h>

void setup() {
  Serial.begin(115200);
  pinMode(D0, INPUT); // btn A
  pinMode(D3, INPUT); // btn B
  pinMode(D1, INPUT); // btn C
  pinMode(D2, INPUT); // btn D
  Network::connectWifi();
  Network::connectMqtt();
}

void loop() {
  
  delay(300);
  
  if (digitalRead(D0) == HIGH) {
    State::change(BTN::A);
  }
   if (digitalRead(D3) == HIGH) {
    State::change(BTN::B);
   }
   if (digitalRead(D1) == HIGH) {
     State::change(BTN::C);
   }
   if (digitalRead(D2) == HIGH) {
     State::change(BTN::D);
   }
  
  Network::checkConnectedWifi();
  Network::checkConnectedMqtt();
}