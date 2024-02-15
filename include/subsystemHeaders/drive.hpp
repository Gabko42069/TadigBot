#include "main.h"

void tankDrive();

void setDriveBrake(pros::motor_brake_mode_e_t brake_type);

void moveIn(double inches, int tout, bool ays, bool f);

void turnBy(float changeTheta, int tout, bool right);

void turnDegree(float x, bool forward);