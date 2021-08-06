#include <Arduino.h>
#include <Network.h>

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
  
  delay(200);
  
  if (digitalRead(D0) == HIGH) {
    Serial.println("btn A turn On state");
    Network::publishMsg("{'cmd':'fx','payload':'1'}");
    Network::publishMsg("{'cmd':'spd','payload':'255'}");
   }
   if (digitalRead(D3) == HIGH) {
     Serial.println("btn B turn Off state");
     Network::publishMsg("{'cmd':'off','payload':''}");
   }
   if (digitalRead(D1) == HIGH) {
     Serial.println("d1 wachin C");
   }
   if (digitalRead(D2) == HIGH) {
     Serial.println("d2 wachin D");
   }
  
  Network::checkConnectedWifi();
  Network::checkConnectedMqtt();
}