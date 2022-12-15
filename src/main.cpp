#include <Arduino.h>
#include <Network.h>
#include <State.h>

#define IR_ON

#ifdef IR_ON
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <StateIR.h>
const uint16_t kRecvPin = D5;
IRrecv irrecv(kRecvPin);
decode_results results;
#endif

void initIR()
{
#ifdef IR_ON
  irrecv.enableIRIn(); // Start the receiver
  while (!Serial)      // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(kRecvPin);
#endif
}

void initRF()
{
  pinMode(D0, INPUT); // btn A
  pinMode(D3, INPUT); // btn B
  pinMode(D1, INPUT); // btn C
  pinMode(D2, INPUT); // btn D
}

void checkIRstate()
{
#ifdef IR_ON
  if (irrecv.decode(&results))
  {
    // print() & println() can't handle printing long longs. (uint64_t)

    if (results.value == CODE::ON)
    {
      StateIR::change(CODE::ON);
    }
    if (results.value == CODE::OFF)
    {
      StateIR::change(CODE::OFF);
    }

    if (results.value == CODE::RED)
    {
      StateIR::change(CODE::RED);
    }
    if (results.value == CODE::CYAN)
    {
      StateIR::change(CODE::CYAN);
    }
    if (results.value == CODE::YELLOW)
    {
      StateIR::change(CODE::YELLOW);
    }
    if (results.value == CODE::BLUE)
    {
      StateIR::change(CODE::BLUE);
    }

    serialPrintUint64(results.value, HEX);
    Serial.println("");
    irrecv.resume(); // Receive the next value
  }
#endif
}

void checkRCstate()
{
  if (digitalRead(D0) == HIGH)
  {
    State::change(BTN::A);
  }
  if (digitalRead(D3) == HIGH)
  {
    State::change(BTN::B);
  }
  if (digitalRead(D1) == HIGH)
  {
    State::change(BTN::C);
  }
  if (digitalRead(D2) == HIGH)
  {
    State::change(BTN::D);
  }
}

void setup()
{
  Serial.begin(115200);
#ifdef IR_ON
  initIR();
#else
  initRF();
#endif
  Network::connectWifi();
  Network::connectMqtt();
}

void loop()
{

#ifdef IR_ON
  checkIRstate();
#else
  checkRCstate();
#endif
  Network::checkConnectedWifi();
  Network::checkConnectedMqtt();
}
