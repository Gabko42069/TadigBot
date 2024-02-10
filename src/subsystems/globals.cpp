#include "lemlib/api.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

pros::Motor leftFront(leftFrontPort, pros ::E_MOTOR_GEARSET_06, true);
pros::Motor leftMiddle(leftMiddlePort, pros ::E_MOTOR_GEARSET_06, true);
pros::Motor leftBack(leftBackPort, pros ::E_MOTOR_GEARSET_06, true);
pros::Motor rightFront(rightFrontPort, pros ::E_MOTOR_GEARSET_06);
pros::Motor rightMiddle(rightMiddlePort, pros ::E_MOTOR_GEARSET_06);
pros::Motor rightBack(rightBackPort, pros ::E_MOTOR_GEARSET_06);

pros::Motor intake(intakePort, pros ::E_MOTOR_GEARSET_06);
pros::Motor cata(cataPort, pros ::E_MOTOR_GEARSET_06,true);
pros::Motor cata2(cata2Port, pros::E_MOTOR_GEARSET_06);
pros::Controller controller(pros ::E_CONTROLLER_MASTER);

pros::Imu inertial(inertialPort);
pros::Rotation rotation(rotationPort);
pros::ADIEncoder shaftEncoder('H','G');
lemlib::TrackingWheel vertTrackingWheel(&shaftEncoder,2.75,2,1);
bool ptoMode = false;

pros::ADIPort backLeftWing(backLeftWingPort, pros::E_ADI_DIGITAL_OUT);
pros::ADIPort backRightWing(backRightWingPort, pros::E_ADI_DIGITAL_OUT);
pros::ADIPort frontLeftWing(frontLeftWingPort, pros::E_ADI_DIGITAL_OUT);
pros::ADIPort frontRightWing(frontRightWingPort, pros::E_ADI_DIGITAL_OUT);
pros::ADIPort pto(ptoPort,pros::E_ADI_DIGITAL_OUT);
pros::ADIPort ptoRatchet(ptoRatchetPort, pros::E_ADI_DIGITAL_OUT);

pros::MotorGroup left_side_motors({leftFront, leftMiddle, leftBack});
pros::MotorGroup right_side_motors({rightFront, rightMiddle, rightBack});

lemlib::Drivetrain drivetrain(&left_side_motors, // left motor group
                              &right_side_motors, // right motor group
                              10, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              450, // drivetrain rpm is 360
                              8 
);

lemlib::ControllerSettings linearController(11, // proportional gain (kP)
                                            0.00, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            200, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0.03, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

lemlib::OdomSensors sensors(&vertTrackingWheel, // vertical tracking wheel 1,
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2,
                            &inertial // inertial sensor
);

lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);
