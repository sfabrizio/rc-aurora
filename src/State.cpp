#include <State.h>

namespace State
{
    boolean isOn = false;
    int spd_set[] = {50, 200, 240, 255};
    int fx_set[] = {1, 255, 4, 5, 6}; // position [1] is set RGB
    // 20 % bright colors:
    String colorsToPlay[] = {"102 0 0", "102 102 0", "102 20 0", "0 102 0", "0 41 102", "77 0 102", "30 0 102"};
    int c_len = 6;   // this has to match color array elements
    int spd_i = 3;   // speed index start at max speed
    int fx_i = 0;    // effect index
    int color_i = 0; // color index

    boolean isColorMode = false;

    void change(byte btn)
    {

        switch (btn)
        {
        case BTN::A:
            toggleOnOff();
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

    void toggleOnOff()
    {
        if (isOn)
        {
            switchOff();
        }
        else
        {
            switchOn();
        }
        isOn = !isOn;
        delay(BTN_DELAY); // x2 delay
    }

    void switchOn()
    {
        if (isColorMode)
        {
            Network::publishMsg(get_currentRgb());
        }
        else
        {
            Network::publishMsg(get_currentFx());
            Network::publishMsg(get_currentSpd());
        }
    }

    void switchOff()
    {
        if (isColorMode)
        {
            fx_i = 1; // remember index state for next ON.
        }
        Network::publishMsg("{'cmd':'off','payload':''}");
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
        if (color_i == c_len)
        {
            Network::publishMsg(get_currentRgb());
            color_i = 0;
            return;
        }
        Network::publishMsg(get_currentRgb());
        color_i++;
    }

    void prev_color()
    {
        if (color_i == 0)
        {
            Network::publishMsg(get_currentRgb());
            color_i = c_len;
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