#include <Commands/WristWithJoysticks.h>
#include "RobotMap.h"

WristWithJoysticks::WristWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
	checkKeys();
}

// Called just before this Command runs the first time
void WristWithJoysticks::Initialize() {
	getPreferences();
	grabber.SetReverseLimit(angle);
}

// Called repeatedly when this Command is scheduled to run
void WristWithJoysticks::Execute() {
	double RT = oi.getAxis(RIGHT_TRIG);
	double LT = oi.getAxis(LEFT_TRIG);

	double speed = RT - LT;

	if(speed > maxSpeed){
		speed = maxSpeed;
	}else if(speed < -maxSpeed){
		speed = -maxSpeed;
	}

	grabber.SimpleWristControl(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool WristWithJoysticks::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void WristWithJoysticks::End() {
	grabber.SimpleWristControl(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristWithJoysticks::Interrupted() {
	grabber.SimpleWristControl(0);
}

void WristWithJoysticks::getPreferences(){
	maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);
	angle = Preferences::GetInstance()->GetDouble("Wrist/Wrist Down Angle", 1);

	grabber.SetMaxSpeed(maxSpeed);
}

void WristWithJoysticks::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Wrist/Max Speed", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Down Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Down Angle", 0.0);
	}
}
