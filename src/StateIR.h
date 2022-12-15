#include <Network.h>

namespace StateIR
{
    void change(uint64_t);
    void switchOn();
    void switchOff();
    void setColor(byte);

};

enum CODE
{
    ON = 0xFFB04F,
    OFF = 0xFFF807,
    RED = 0xFF9867,
    CYAN = 0xFF48B7,
    YELLOW = 0xFF38C7,
    BLUE = 0xFF6897,

};