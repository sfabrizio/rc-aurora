#include <State.h>

namespace State
{
    boolean isOn = false;
    boolean isColorMode = false;
    int spd_set[] = {255, 240, 200, 50};
    int fx_set[] = {1, 255, 4, 5, 6}; // position [1] is setRGB cmd
    // 20% bright on these color values:
    String colorsToPlay[] = {"102 0 0", "102 102 0", "102 20 0", "0 102 0", "0 41 102", "77 0 102", "30 0 102"};
    //  red, yellow, orange, green, cyan, pink, violeta

    int c_len = 6;    // this has to match color array elements
    int spd_i = -1;   // speed index
    int fx_i = -1;    // effect index
    int color_i = -1; // color index

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
        if (fx_i == -1)
        {
            next_effect();
        }
        return "{'cmd':'fx','payload':'" + String(fx_set[fx_i]) + "'}";
    }

    String get_currentSpd()
    {
        if (spd_i == -1)
        {
            speed_down(); // start a max speed
        }
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
        Network::publishMsg("{'cmd':'off','payload':''}");
    }

    void next_effect()
    {
        isColorMode = false;
        fx_i++;
        if (fx_i > 4)
        {
            fx_i = 0;
        }
        if (fx_i == 1) // rgb mode
        {
            isColorMode = true;
            next_color();
            return;
        }
        Network::publishMsg(get_currentFx());
    }

    void next_color()
    {
        color_i++;

        if (color_i > c_len)
        {
            color_i = 0;
            return;
        }
        Network::publishMsg(get_currentRgb());
    }

    void prev_color()
    {
        color_i--;
        if (color_i < 0)
        {
            color_i = c_len;
        }
        Network::publishMsg(get_currentRgb());
    }

    void speed_up()
    {
        spd_i--;

        if (spd_i < 0)
        {
            spd_i = 3;
        }
        Network::publishMsg(get_currentSpd());
    }

    void speed_down()
    {

        spd_i++;
        if (spd_i > 3)
        {
            spd_i = 0;
        }
        Network::publishMsg(get_currentSpd());
    }
};