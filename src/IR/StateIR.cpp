#include <StateIR.h>

namespace StateIR
{
    // 20% bright on these color values:
    String colorsToPlay[] = {"102 0 0", "0 102 0", "102 102 0", "30 0 102", "128 0 127"};
    // red, green, yellow, violeta/blue , pink
    void change(uint64_t code)
    {
        switch (code)
        {
        case CODE::ON:
            switchOn();
            break;
        case CODE::OFF:
            switchOff();
            break;
        case CODE::RED:
            setColor(0);
            break;
        case CODE::GREEN:
            setColor(1);
            break;
        case CODE::YELLOW:
            setColor(2);
            break;
        case CODE::BLUE:
            setColor(3);
            break;
        case CODE::WHITE:
            whiteEffect();
            break;
        case CODE::PINK:
            setColor(4);
            break;
        case CODE::SMOOTH:
            smoothEffect();
            break;
        case CODE::FLASH:
            flashEffect();
            break;
        case CODE::STROBE:
            flashEffect();
            break;
        default:
            return;
        }
    }

    void strobeEffect()
    {
        Network::publishMsg("{'cmd':'fx','payload':'9'}");
        Network::publishMsg("{'cmd':'spd','payload':'255'}");
    }
    void flashEffect()
    {
        Network::publishMsg("{'cmd':'fx','payload':'9'}");
        Network::publishMsg("{'cmd':'spd','payload':'250'}");
    }

    void whiteEffect()
    {
        Network::publishMsg("{'cmd':'fx','payload':'7'}");
        Network::publishMsg("{'cmd':'spd','payload':'150'}");
    }

    void smoothEffect()
    {
        Network::publishMsg("{'cmd':'fx','payload':'2'}");
        Network::publishMsg("{'cmd':'spd','payload':'250'}");
    }

    void switchOn()
    {
        Network::publishMsg("{'cmd':'fx','payload':'1'}");
    }

    void switchOff()
    {
        Network::publishMsg("{'cmd':'off','payload':''}");
    }

    void setColor(byte color)
    {
        Network::publishMsg("{'cmd':'setRGB','payload':'" + String(colorsToPlay[color]) + "'}");
    }
}