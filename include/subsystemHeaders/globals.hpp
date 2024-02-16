#include "lemlib/api.hpp"
#include "main.h"
#include "pros/adi.hpp"

//Motors
extern pros::Motor leftFront;
extern pros::Motor leftMiddle;
extern pros::Motor leftBack;
extern pros::Motor rightFront;
extern pros::Motor rightMiddle;
extern pros::Motor rightBack;

extern pros::Motor intake;
extern pros::Motor cata;
extern pros::Motor cata2;

//sensors and other dubious things of that nature 
extern pros::Controller controller;
extern pros::Imu inertial;
extern pros::Rotation rotation;
extern pros::ADIEncoder shaftEncoder;
extern lemlib::TrackingWheel vertTrackingWheel;
extern bool ptoMode;

//lemlib(the active ingredient)
extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;
/*
extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings linearController;
extern lemlib::ControllerSettings angularController;
extern lemlib::OdomSensors sensors;
*/

extern lemlib::Drivetrain_t drivetrain;
extern lemlib::OdomSensors_t sensors;
extern lemlib::ChassisController_t lateralController;
extern lemlib::ChassisController_t angularController;
extern lemlib::Chassis chassis;


//pistons and such
extern pros::ADIPort backLeftWing;
extern pros::ADIPort backRightWing;
extern pros::ADIPort frontLeftWing;
extern pros::ADIPort frontRightWing;
extern pros::ADIPort pto;
extern pros::ADIPort ptoRatchet;

#define leftFrontPort 5
#define leftMiddlePort 6
#define leftBackPort 7 
#define rightFrontPort 4
#define rightMiddlePort 3
#define rightBackPort 2

#define intakePort 8
#define cataPort 11    
#define cata2Port 10

#define inertialPort 1
#define rotationPort 9

#define backLeftWingPort 'B'
#define backRightWingPort 'F'
#define frontLeftWingPort 'D'
#define frontRightWingPort 'E'

#define ptoPort 'A'
#define ptoRatchetPort 'C'
