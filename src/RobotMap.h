#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//DriveTrain PWM Pins
constexpr int DRIVE_LEFT = 0;
constexpr int DRIVE_RIGHT = 1;
constexpr int WINCH_REEL = 2;


//Joystick Ports
constexpr int JOY_DRIVER = 0;

//joystick Button IDs
constexpr int BUTTON_A = 1;
constexpr int BUTTON_B = 2;
constexpr int BUTTON_X = 3;
constexpr int BUTTON_Y = 4;
constexpr int LEFT_BUM = 5;
constexpr int RIGHT_BUM = 6;

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
constexpr int ELEVATOR_FORWARD = 0;
constexpr int ELEVATOR_BACKWARD = 1;
constexpr int CLAW_FORWARD = 2;
constexpr int CLAW_BACKWARD = 3;
constexpr int WINCH_RELEASE = 4;

//TalonSRX ID
constexpr int WRIST_ID = 2;
constexpr int WRIST_SLOT = 0;
constexpr int WRIST_LOOP = 0;
constexpr int WRIST_TIMEOUT = 10;

//Robot Length
constexpr double ROBOT_LENGTH = 23.82;

#endif  // ROBOTMAP_H
