#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"

void liftControl() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) &&
      controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    pto.set_value(!pto.get_value());
    ptoMode = !ptoMode;
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    cata2.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) &&
      (ptoMode == true)) {
    cata = 127;
    cata2 = 127;
    pros::delay(2000);
    cata = 0;
    cata2 = 0;
  } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) &&
             ptoMode) {
    cata = -127;
    cata = -127;
    pros::delay(5000);
    ptoRatchet.set_value(!ptoRatchet.get_value());
    cata = 0;
    cata2 = 0;
  }
}