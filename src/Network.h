#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define WIFI_SSID "Wifi name"
#define WIFI_PWD "password"
#define MQTT_SERVER "192.168.1.200"
#define MQTT_PORT 1883

namespace Network {
  void connectWifi();
  void connectMqtt();
  void checkConnectedWifi();
  void checkConnectedMqtt();
  void publishMsg(String);
}
