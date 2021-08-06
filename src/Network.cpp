#include <Network.h>

namespace Network
{

  WiFiClient espClient;
  PubSubClient client(espClient);

  void connectWifi()
  {

    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(WIFI_SSID);

    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PWD);

    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }

  void connectMqtt()
  {
    //connecting to a mqtt broker
    client.setServer(MQTT_SERVER, MQTT_PORT);
    String client_id = "rc-aurora-";
    while (!client.connected())
    {
      client_id += String(WiFi.macAddress());
      Serial.println("Connecting to mqtt broker.....");
      if (client.connect(client_id.c_str()))
      {
        Serial.println("MQTT broker connected");
      }
      else
      {
        Serial.print("failed with state ");
        Serial.print(client.state());
        delay(5000);
      }
    }
    // publish and subscribe
    client.publish("myhome",client_id.c_str());
  }

void publishMsg(String msg) {
  client.publish("myhome", msg.c_str());
}

void checkConnectedMqtt() {

  if (!client.connected()) {
    connectMqtt();
  }
}

  /**
* checks the connection is still alive, if not resets the device
*/
  void checkConnectedWifi()
  {
    if (!WiFi.isConnected())
    {
      Serial.println("Wifi disconnected, attempting to reconnect");
      connectWifi();
    }
  }

}