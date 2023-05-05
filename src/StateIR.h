#include <Network.h>

namespace StateIR
{
    void change(uint64_t);
    void switchOn();
    void switchOff();
    void setColor(byte);
    void smoothEffect();
    void whiteEffect();
    void flashEffect();
    void strobeEffect();
};

enum CODE
{
    // cmd
    ON = 0xFFE01F,
    OFF = 0xFF609F,
    // colors
    RED = 0xFF10EF,
    GREEN = 0xFF906F,
    YELLOW = 0xFF18E7,
    BLUE = 0xFF708F,
    WHITE = 0xFFC03F,
    PINK = 0xFF58A7,
    // effects
    SMOOTH = 0xFFE817,
    FLASH = 0xFFF00F,
    STROBE = 0xFFC837,
};