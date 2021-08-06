#include <Arduino.h>
#include <Network.h>

void setup() {
  Serial.begin(115200);
  pinMode(D0, INPUT); // btn A
  pinMode(D3, INPUT); // btn B
  pinMode(D1, INPUT); // btn C
  pinMode(D2, INPUT); // btn D
  Serial.println("init..");
  Network::connectWifi();
}

void loop() {

  delay(200);

  if (digitalRead(D0) == HIGH) {
     Serial.println("d0 wachin A");
   }
   if (digitalRead(D3) == HIGH) {
     Serial.println("d3 wachin B");
   }
   if (digitalRead(D1) == HIGH) {
     Serial.println("d1 wachin C");
   }
   if (digitalRead(D2) == HIGH) {
     Serial.println("d2 wachin D");
   }
  
  Network::checkConnectedWifi();
}