#include "main.h"

void setCata(int power)
{
    cata = power;
    cata2 = power;
}

void controlCata()
{
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) && !ptoMode) {
    pros ::Task shoot_cata(cataAysnc, TASK_PRIORITY_MIN);
  }

}

void cataAysnc() {
  pros::delay(10);
  rotation.set_position(0);
  cata = 127;
  cata2 = 127;
  pros::delay(300);
  setCata(0);
  while(rotation.get_position() < 14000) { //change value
    cata = 127;
    cata2 = 127;
    pros::delay(10);
  }
  setCata(0);
}