#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/llemu.hpp"
#include <string>

static float TO_RADIANS = 0.0174533;
static float TO_DEGREES = 57.2958;

void tankDrive() {
  int l_stick = controller.get_analog(ANALOG_LEFT_Y);
  int r_stick = controller.get_analog(ANALOG_RIGHT_Y);
  chassis.tank(l_stick, r_stick, 0);
}

void setDriveBrake(pros::motor_brake_mode_e_t brake_type) {
  left_side_motors.set_brake_modes(brake_type);
  right_side_motors.set_brake_modes(brake_type);
}

void moveIn(double inches, int tout, bool ays = false, bool f = true) {
  lemlib::Pose current = chassis.getPose(true);
  float oldX = current.x;
  float oldY = current.y;
  float theta = current.theta;
  if (f) {
    int newX = inches * sin(theta) + oldX;
    int newY = inches * cos(theta) + oldY;
    chassis.moveTo(newX, newY, (theta * TO_DEGREES), tout, ays, true, 0, 0);
  }
  if (!f) {
    int newX = oldX - inches * sin(theta);
    int newY = oldY - inches * cos(theta);
    chassis.moveTo(newX, newY, (TO_DEGREES * theta), tout, ays, false, 0, 0);
  }
}
void turnBy(float changeTheta, int tout, bool right = true) {
  lemlib::Pose current = chassis.getPose(false);
  float X = current.x;
  float Y = current.y;
  float oldtheta = current.theta;

  //  double toAngle=right?currentAngle+changeTheta:currentAngle-changeTheta;
  if (right) {
    // lemlib::Pose newDeg = current.rotate(changeTheta * TO_RADIANS);
    current.theta += changeTheta;
    float faceX = X + (10 * sin(current.theta * TO_RADIANS));
    float faceY = Y + (10 * cos(current.theta * TO_RADIANS));
    chassis.turnTo(faceX, faceY, tout);
  } else {
    current.theta -= changeTheta;
    float faceX = X + (10 * sin(current.theta * TO_RADIANS));
    float faceY = Y + (10 * cos(current.theta * TO_RADIANS));
    chassis.turnTo(faceX, faceY, tout);
  }
  // lemlib::Pose check = chassis.getPose();
  // std::string display = "currentheading" + check.theta;
  //  pros::lcd::set_text(8, "currentheading" + check.theta);
}

void turnDegree(float x, bool forward) {
  // lemlib::Pose current = chassis.getPose();
  float X = chassis.getPose().x;
  float Y = chassis.getPose().y;
  float oldtheta = chassis.getPose().theta;
  if (forward) {
    float faceX = X + (10 * sin(x * TO_RADIANS));
    float faceY = Y + (10 * cos(x * TO_RADIANS));
    chassis.turnTo(faceX, faceY, 1200);
  } else {
    float faceX = X - (10 * sin(x * TO_RADIANS));
    float faceY = Y - (10 * cos(x * TO_RADIANS));
    chassis.turnTo(faceX, faceY, 1200);
  }
}
