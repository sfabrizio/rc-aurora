#include <Network.h>

namespace State {
    void change(byte);
    void switchOnOff();
    void next_effect();
    void speed_up();
    void speed_down();
};

enum BTN {
  A,
  B,
  C,
  D
};