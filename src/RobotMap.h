#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//DriveTrain PWM Pins
constexpr int DRIVE_LEFT = 0;
constexpr int DRIVE_RIGHT = 1;

//Joystick Ports
constexpr int JOY_DRIVER = 0;

//joystick Button IDs
constexpr int BUTTON_A = 1;
constexpr int BUTTON_B = 2;
constexpr int BUTTON_X = 3;
constexpr int BUTTON_Y = 4;

//Axis IDs
constexpr int LEFT_X = 0;
constexpr int LEFT_Y = 1;
constexpr int RIGHT_X = 4;
constexpr int RIGHT_Y = 5;
constexpr int LEFT_TRIG = 2;
constexpr int RIGHT_TRIG = 3;

//Encoder Channels
constexpr int LA_CHANNEL = 0;
constexpr int LB_CHANNEL = 1;
constexpr int RA_CHANNEL = 2;
constexpr int RB_CHANNEL = 3;

//Pneumatics Ports
constexpr int PNEU_GRABBER = 0;
constexpr int CLAW = 1;

//Autonomous Target Tolerances (+-target value)
constexpr double TURN_TARGET = 1;
constexpr double DRIVE_TARGET = 1.5;

#endif  // ROBOTMAP_H
