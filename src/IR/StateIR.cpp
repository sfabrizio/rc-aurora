#include <StateIR.h>

namespace StateIR
{
    // 20% bright on these color values:
    String colorsToPlay[] = {"102 0 0", "0 41 102", "102 102 0", "30 0 102"};
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
        case CODE::CYAN:
            setColor(1);
            break;
        case CODE::YELLOW:
            setColor(2);
            break;
        case CODE::BLUE:
            setColor(3);
            break;
        default:
            return;
        }
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