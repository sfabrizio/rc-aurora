#include <State.h>

namespace State
{
    boolean isOn = false;
    int spd_set[] = {50, 200, 240, 255};
    int fx_set[] = {1, 255, 4, 5, 6}; // position [1] is set RGB
    String colorsToPlay[] = {"150 0 0", "51 0 51", "46 0 77", "42 128 0", "0 77 102"};

    int spd_i = 2; // start at max speed
    int fx_i = 0;
    int color_i = 0;

    boolean isColorMode = false;

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
            isColorMode ? prev_color() : speed_down();
            delay(BTN_DELAY);
            break;
        case BTN::D:
            isColorMode ? next_color() : speed_up();
            delay(BTN_DELAY);
            break;
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

    String get_currentRgb()
    {
        return "{'cmd':'setRGB','payload':'" + String(colorsToPlay[color_i]) + "'}";
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
        delay(BTN_DELAY); // x2 delay
    }

    void next_effect()
    {
        isColorMode = false;
        if (fx_i == 1) // rgb mode
        {
            isColorMode = true;
            Network::publishMsg(get_currentRgb());
            fx_i++;
            return;
        }
        if (fx_i == 4)
        {
            Network::publishMsg(get_currentFx());
            fx_i = 0;
            return;
        }

        Network::publishMsg(get_currentFx());
        fx_i++;
    }

    void next_color()
    {
        color_i++;
        if (color_i == 4)
        {
            Network::publishMsg(get_currentRgb());
            color_i = 0;
            return;
        }
        Network::publishMsg(get_currentRgb());
    }

    void prev_color()
    {
        if (color_i == 0)
        {
            Network::publishMsg(get_currentRgb());
            color_i = 4;
            return;
        }
        Network::publishMsg(get_currentRgb());
        color_i--;
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