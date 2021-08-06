#include <Network.h>

#define BTN_DELAY 400

namespace State {
    void change(byte);
    void switchOnOff();
    void next_effect();
    void speed_up();
    void speed_down();
    void next_color();
    void prev_color();
    String get_currentFx();
    String get_currentSpd();
};

enum BTN {
  A,
  B,
  C,
  D
};