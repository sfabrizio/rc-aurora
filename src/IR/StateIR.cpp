#include <StateIR.h>

namespace StateIR
{
    // 20% bright on these color values:
    String colorsToPlay[] = {"102 0 0", "0 102 0", "102 102 0", "30 0 102"};
    // red, cyan, yellow, violeta
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
        case CODE::SMOOTH:
            smoothEffect();
            break;
        default:
            return;
        }
    }

    void smoothEffect()
    {
        Network::publishMsg("{'cmd':'fx','payload':'1'}");
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