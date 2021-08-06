#include <State.h>

namespace State
{
    boolean isOn = false;
    int spd_set[] = {50, 200, 240, 255};
    int fx_set[] = {1, 2, 3, 4};
    int spd_i = 2; // start at max speed
    int fx_i = 0;

    void change(byte btn)
    {

        switch (btn)
        {
        case BTN::A:
            switchOnOff();
            delay(BTN_DELAY);
            break;
        case BTN::B:
            next_effect();
            delay(BTN_DELAY);
            break;
        case BTN::C:
            speed_down();
            delay(BTN_DELAY);
            break;
        case BTN::D:
            speed_up();
            delay(BTN_DELAY);
            break;
        }
    }

    void switchOnOff()
    {
        if (isOn)
        {
            Network::publishMsg("{'cmd':'off','payload':''}");
            isOn = false;
        }
        else
        {
            Network::publishMsg(get_currentFx());
            Network::publishMsg(get_currentSpd());
            isOn = true;
        }
    }

    String get_currentFx()
    {
        return "{'cmd':'fx','payload':'" + String(fx_set[fx_i]) + "'}";
    }

    String get_currentSpd()
    {
        return "{'cmd':'spd','payload':'" + String(spd_set[spd_i]) + "'}";
    }

    void next_effect()
    {
        if (fx_i == 3)
        {
            fx_i = 0;
            Network::publishMsg(get_currentFx());
            return;
        }

        fx_i++;
        Network::publishMsg(get_currentFx());
    }

    void speed_up()
    {
        if (spd_i == 3)
        {
            spd_i = 0;
            Network::publishMsg(get_currentSpd());
            return;
        }

        spd_i++;
        Network::publishMsg(get_currentSpd());
    }
    void speed_down()
    {
        if (spd_i == 0)
        {
            spd_i = 3;
            Network::publishMsg(get_currentSpd());
            return;
        }

        spd_i--;
        Network::publishMsg(get_currentSpd());
    }
};