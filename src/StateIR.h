#include <Network.h>

namespace StateIR
{
    void change(uint64_t);
    void switchOn();
    void switchOff();
    void setColor(byte);
    void smoothEffect();
};

enum CODE
{
    ON = 0xFFE01F,
    OFF = 0xFF609F,
    RED = 0xFF10EF,
    GREEN = 0xFF906F,
    YELLOW = 0xFF18E7,
    BLUE = 0xFF708F,
    SMOOTH = 0xFFE817,
    PINK = 0xFF58A7,
};