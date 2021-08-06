# RC Aurora

Simple RC receptor over ESP8266 for send commands to [aurora](https://github.com/garhul/aurora) broker. The idea is just control the light with my RCs controls.
Main features: ON/OFF, Pass effects & Adjust effect's speed or Color if applies.

## Hardware

- RC control 433MHZ with 4 channels
- Receptor RX480-E4 with 4 channels
- D1 mini (ESP8266)

## Software

This is done on platformio, so it's quite straight forward flash on VS code whit it. Also is possible changhe the board model if you need to, the code stay the same.

## Config

In `Network.h` you should set you WIFI credential & your mqtt broker address. That's it, set those and flash.

```
// Network.h
#define WIFI_SSID "Your wifi"
#define WIFI_PWD "wifi password"
#define MQTT_SERVER "192.168.1.200" // broker ip/hostname
#define MQTT_PORT 1883 // broker port
...
```

Relarted Projects:

- [aurora](https://github.com/garhul/aurora)
- [aurora-mqtt-server](https://github.com/sfabrizio/aurora-mqtt-server)
- [aurora-alexa](https://github.com/sfabrizio/aurora-alexa)
