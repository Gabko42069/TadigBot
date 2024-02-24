#include "lemlib/api.hpp"
#include "main.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

void sixBall() {
   pros::Task shootypoo(cataAysnc,TASK_PRIORITY_MIN);
   setIntake(127);
   pros::delay(500);
   chassis.setPose(29.712, -58.004, 270);
   chassis.moveTo(12, -58.004, 270, 1000,false,true,0,0); //go forward to ball under bar
   chassis.moveTo(29.712, -58.004, 270, 1500,false,false); //come back to starting point
   //setIntake(0);
   //chassis.turnTo(47.326, -45.939, 1000,false, true); //turn butt to goal
   //chassis.moveTo(47.326, -45.939, 235, 1500, false, false,0,0);
   chassis.moveTo(60, -28, 180, 2000,true,false,8,.35);//curve to triball in corner 
   pros::delay(500);
   backLeftWing.set_value(!backLeftWing.get_value());//smack that shi out 
   backRightWing.set_value(!backRightWing.get_value());
   pros::delay(400);
   backLeftWing.set_value(!backLeftWing.get_value());
   backRightWing.set_value(!backRightWing.get_value());
   pros::delay(1000);
   moveIn(10, 1000, false, true);
   chassis.turnTo(61,-28, 1000); //turn 180 to face goal with intake
   /*
   setIntake(-127); //outtake into goal
   chassis.moveTo(53.639, -36.369, 55, 1500,false,true,0,0); //move to in front of goal
   chassis.turnTo(53.639,-25.603, 1000); //turn to become straight with the goal with intake
   chassis.moveTo(53.639, -25.603, 0, 1000,false,true,0,0); //push balls into goal with intake
   chassis.moveTo(53.639, -40, 0, 1000,false,false); //back out of goal
   chassis.turnTo(12.786, -26.012, 1000); // turn to barrierside bottom ball
   setIntake(127);
   chassis.moveTo(12.786, -26.012, 287, 1000,false,true,6,.6); //move to barrierside bottom ball
   pros::delay(100);
   chassis.turnTo(42.333,-13.625, 1000);//turn to goal with ball
   setIntake(-127);
   moveIn(8,1500,false,true);
   chassis.turnTo(0,0,1000);
   setIntake(127);
   moveIn(16,1500,false,true);
   chassis.turnTo(55, 0, 1000); //turn to mid left ball
   setIntake(127);
   frontLeftWing.set_value(!frontLeftWing.get_value());
   frontRightWing.set_value(!frontRightWing.get_value());
   moveIn(1000,2000,false,true);
   /*
   chassis.moveTo(8.957, -6.822, 350, 1000); //move to mid left ball
   chassis.turnTo(16.889, -3.466, 1000); //turn to mid rit ball
   chassis.moveTo(16.889, -3.466, 68, 1000); //turn to mid rit ball
   frontRightWing.set_value(!frontRightWing.get_value());
   frontLeftWing.set_value(!frontLeftWing.get_value());
   chassis.turnTo(50, -3.466, 1000); //turn to strait goal
   chassis.moveTo(50, -3.466, 90, 1000); //move strait to goal
   */
}


void gabRight(){
chassis.setPose(41.149, -53.425, 0);
frontRightWing.set_value(!frontRightWing.get_value());
pros::delay(300);
frontRightWing.set_value(!frontRightWing.get_value());
setIntake(127);
chassis.moveTo(8.179, -3.842,-30,2000,false,true, 0,0);
chassis.turnTo(55,-3.842,1500);
frontRightWing.set_value(!frontRightWing.get_value());
chassis.moveTo(43, -3.842,90,2000,false,true, 0,0);
frontRightWing.set_value(!frontRightWing.get_value());
chassis.moveTo(38, -3.842,90,2000,false,false, 0,0);
chassis.turnTo(10, -19, 1500);
chassis.moveTo(10, -19, 235, 2000,false,true,0,0);
chassis.turnTo(55.858, -49.227, 1500);
chassis.moveTo(55.858, -49.227,122, 2000);
 //move to first triball 

}

void leftWP() {
  cataAysnc();
  chassis.setPose(-41.149, -53.425, 90);
  chassis.turnTo(-30.115, -62.585, 1000);// TURN butt TO GOAL

  chassis.moveTo(-57.876, -39.452, 130, 1200, false, false, 0, 0); //drive diag to goal
  chassis.turnTo(-57.876, 0, 1500, false, true); //turn butt to goal straight
  chassis.moveTo(-57.876, -32.5, 180, 1000, false, false, 8) ;//puash ball in goal
  chassis.moveTo(-57.876, -38, 180, 1000); //get away from goal
  chassis.turnTo(-44.615,-53.175 , 1500); //turn to mathload
  chassis.moveTo(-44.615,-53.175, 145,1500,false,true,0,0);//move to mathload
  backLeftWing.set_value(!backLeftWing.get_value());
  chassis.turnTo(-32,-53.175,1000,false);
  chassis.turnTo(-44.615, -32, 1000);
  chassis.turnTo(-75, -53.175, 1000);
  backLeftWing.set_value(!backLeftWing.get_value());
  turnBy(20, 1000, true);
  moveIn(37, 1000, false, false);
  //turnDegree(90,false);
  //chassis.turnTo(-50,-53.175,1000,false,false,70);


  //moveIn(3, 1000, false, false);
  //moveIn(7, 1000, false, true);
  
  /*
  pros::c::delay(400);
  chassis.turnTo(-55, 0, 1500, false, false, 70);
  moveIn(6,1000,false,false);
  chassis.turnTo(-42, -60, 1000, false,true);
  backLeftWing.set_value(!backLeftWing.get_value());
  moveIn(12,1500,false,false);
  */

  // turnDegree(90, true);
  // turnDegree(0, true);
  //  turnDegree(0, true);
  //   turnDegree(-10, true);
}

void oneBall()
{
  cataAysnc();
  chassis.setPose(0,0,180);
  chassis.moveTo(0, 100, 180, 3000,false,false);
  chassis.moveTo(0, 15, 180, 3000,false,true);
}

void left() {
  chassis.setPose(-29, -57, 0);
  moveIn(36, 1000, false, true);
  turnDegree(270, true);
  moveIn(36, 1200, true, false);
  setIntake(-127);
  backLeftWing.set_value(!backLeftWing.get_value());
  backRightWing.set_value(!backRightWing.get_value());
  pros::delay(600);
  setIntake(0);
  pros::delay(400);
  backLeftWing.set_value(!backLeftWing.get_value());
  backRightWing.set_value(!backRightWing.get_value());
  pros::delay(400);
  turnDegree(-135, true);
  moveIn(45, 2000, false, true);
  turnDegree(135, true);
  frontRightWing.set_value(!frontRightWing.get_value());
  moveIn(12, 1000, false, true);
  turnDegree(95, true);
  frontRightWing.set_value(!frontRightWing.get_value());
}

void tester() {
  setDriveBrake(pros::E_MOTOR_BRAKE_BRAKE);
  lemlib::Pose pose(0, 0, 0);
  chassis.setPose(pose);
  // moveIn(24,2000,false, true);
  turnDegree(90, true);
}

void sabotage()
{
  chassis.setPose(-29,-53,0);
  frontRightWing.set_value(!frontRightWing.get_value());
  pros::delay(1000);
  frontRightWing.set_value(!frontRightWing.get_value());
  setIntake(127);
  moveIn(40,2000,false,true);
  chassis.turnTo(0, -5, 1000);
  setIntake(-127);
  frontLeftWing.set_value(!frontLeftWing.get_value());
  frontRightWing.set_value(!frontRightWing.get_value());
  setIntake(-127);
  moveIn(26,2000,false,true);
  frontLeftWing.set_value(!frontLeftWing.get_value());
  frontRightWing.set_value(!frontRightWing.get_value());
  chassis.moveTo(-55, -29, 180, 3000,false,false);
  chassis.moveTo(-50, -41, 195, 1000,false,true,8,.2);
  chassis.turnTo(-50, -58, 1500,false,true);
  backRightWing.set_value(1);
  //chassis.moveTo(-43, -57, 90, 2000,false,true);
  //chassis.turnTo(-6, -60, 1000);
  backRightWing.set_value(0);
 // moveIn(35,2000,false,true);
}

void skills()
{

}