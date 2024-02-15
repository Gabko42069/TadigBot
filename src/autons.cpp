#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "main.h"
#include "pros/motors.h"

void sixBall() {
  chassis.setPose(40, -57, 0);
  // changeMode(rightWing);
  chassis.moveTo(6, -9, -30, 1000, true, true, 0, 0);
  pros::delay(400);
  // changeMode(rightWing);
  setIntake(-127);
  pros::delay(600);
  turnDegree(90, true);
  moveIn(34, 1000, true, true);
  pros::delay(300);
  setIntake(127);
  pros::delay(700);
  setIntake(0);
  moveIn(14, 1000, false, false);
  lemlib::Pose current = chassis.getPose(false);
  chassis.moveTo(9, -20, current.theta, 1000, true, true, 0, 0);
  pros::delay(500);
  setIntake(-127);
  pros::delay(500);
  chassis.moveTo(35, -44, 135, 1000, false, true, 0, 0);
  setIntake(127);
  pros::delay(400);
  setIntake(0);
  chassis.moveTo(35, -58, -90, 1500, false, true, 0, 0);
  current = chassis.getPose(false);
  chassis.moveTo(6, -58, current.theta, 1200, true);
  pros::delay(500);
  setIntake(-127);
  pros::delay(700);
}

void leftWP() {
  cataAysnc();
  chassis.setPose(-41.149, -53.425, 90);
  chassis.turnTo(-32.969, -63.159, 1000);
  moveIn(27, 1000, false, false);
  // chassis.moveTo(-56.163, -34.891, 140, 1200, false, false, 0, 0);
  chassis.turnTo(-55, 0, 1500, false, true, 70);
  moveIn(3, 1000, false, false);
  moveIn(7, 1000, false, true);
  pros::delay(400);
  chassis.turnTo(-55, 0, 1500, false, false, 70);
  // turnDegree(90, true);
  // turnDegree(0, true);
  //  turnDegree(0, true);
  //   turnDegree(-10, true);
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