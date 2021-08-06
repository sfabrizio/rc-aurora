#include <State.h>

namespace State
{
    boolean isOn = false;

    void change(byte btn)
    {

        switch (btn)
        {
        case BTN::A:
            switchOnOff();
            break;
        case BTN::B:
            next_effect();
            break;
        case BTN::C:
            speed_up();
            break;
        case BTN::D:
            speed_down();
            break;
        }
    }

    void switchOnOff()
    {
        Serial.println("switchOnOff");
        if (isOn)
        {
            Network::publishMsg("{'cmd':'off','payload':''}");
            isOn = false;
        }
        else
        {
            Network::publishMsg("{'cmd':'fx','payload':'1'}");
            Network::publishMsg("{'cmd':'spd','payload':'255'}");
            isOn = true;
        }
    }

    void next_effect()
    {
        Serial.println("next_effect");
    }

    void speed_up()
    {
        Serial.println("speed_up");
    }
    void speed_down()
    {
        Serial.println("speed_down");
    }
};