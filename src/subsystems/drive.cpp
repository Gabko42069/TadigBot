#include "main.h"


void tankDrive() {
  int l_stick = controller.get_analog(ANALOG_LEFT_Y);
  int r_stick = controller.get_analog(ANALOG_RIGHT_Y);
  chassis.tank(l_stick, r_stick, 0);
}