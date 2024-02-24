#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
  bool uppytoggle = false;
  bool downtoggle = false;

void liftControl() {
  if(ptoMode)
  {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1))
    {
      uppytoggle = !uppytoggle;
      pros::Task uppies(uppy, TASK_PRIORITY_MIN);
    } 
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) 
    {
     downtoggle = !downtoggle;
     pros::Task downies(downy,TASK_PRIORITY_MIN);
    }
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))
    {
      ptoRatchet.set_value(!ptoRatchet.get_value());
    }
  }
  if(!ptoMode)
  {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    pros ::Task shoot_cata(cataAysnc, TASK_PRIORITY_MIN);
    }
    if(controller.get_digital(DIGITAL_L1))
    {
      backLeftWing.set_value(1);
      backRightWing.set_value(1);
    } else if(controller.get_digital(DIGITAL_L2))
    {
      frontLeftWing.set_value(1);
      frontRightWing.set_value(1);
    }else{
      backLeftWing.set_value(0);
      backRightWing.set_value(0);
      frontLeftWing.set_value(0);
      frontRightWing.set_value(0);
    }
  }
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) &&
      controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    pto.set_value(!pto.get_value());
    ptoMode = true;
    pros::Task meshIt(mesh, TASK_PRIORITY_MIN);
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    cata2.set_brake_mode(MOTOR_BRAKE_HOLD);
    ptoRatchet.set_value(!ptoRatchet.get_value());
  }
  
}

void uppy() //gimme uppys
{
  if(uppytoggle){
  cata = 127;
  cata2 = 127;
  }
  if(!uppytoggle)
  {
    cata = 0;
    cata2 = 0;
  }
}

void downy()
{
  if(downtoggle){
  cata = -127;
  cata2 = -127;
  }
  if(!downtoggle)
  {
    cata = 0;
    cata2 = 0;
  }

}

void mesh()
{
  for(int a = 0; a<20 ;a++){
  cata = -127;
  cata2 = -127;
  pros::delay(100);
  cata = 127;
  cata2 = 127;
  pros::delay(100);
  }
  cata = 0;
  cata2 = 0;
}