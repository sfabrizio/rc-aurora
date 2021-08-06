#include <Network.h>

#define BTN_DELAY 350

namespace State {
    void change(byte);
    void switchOnOff();
    void next_effect();
    void speed_up();
    void speed_down();
    String get_currentFx();
    String get_currentSpd();
};

enum BTN {
  A,
  B,
  C,
  D
};