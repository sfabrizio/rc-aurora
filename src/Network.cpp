#include <Network.h>

namespace Network
{

  WiFiClient espClient;
  PubSubClient client(espClient);
  // unsigned long lastMsg = 0;
  // #define MSG_BUFFER_SIZE	(50)
  // char msg[MSG_BUFFER_SIZE];
  // int value = 0;

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
    // Loop until we're reconnected
    while (!client.connected())
    {
      Serial.print("Attempting MQTT connection...");
      // Create a random client ID

      String clientId = "rc-aurora-";
      clientId += String(random(0xffff), HEX);
      // Attempt to connect
      if (client.connect(clientId.c_str()))
      {
        Serial.println("connected");
        // Once connected, publish an announcement...
        client.publish("myhome", "RC control connected");
        // ... and resubscribe
        // client.subscribe("myhome");
      }
      else
      {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        // Wait 5 seconds before retrying
        delay(5000);
      }
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