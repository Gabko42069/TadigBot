#include "main.h"
#include "pros/misc.h"

//bool front=false;
//bool back=false;
void controlWings() {
  if (controller.get_digital_new_press(DIGITAL_RIGHT)) {
    frontLeftWing.set_value(!frontLeftWing.get_value());
    frontRightWing.set_value(!frontRightWing.get_value());
  }
  if (controller.get_digital_new_press(DIGITAL_LEFT)) {
    backLeftWing.set_value(!backLeftWing.get_value());
    backRightWing.set_value(!backRightWing.get_value());
  }
}