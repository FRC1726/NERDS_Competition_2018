#include "Commands/RotateWrist.h"
#include "RobotMap.h"

#include <Preferences.h>

RotateWrist::RotateWrist() : CommandBase("Rotate Wrist") {
	Requires(&grabber);
	checkKeys();
}

// Called just before this Command runs the first time
void RotateWrist::Initialize() {
	getPreferences();
	grabber.SetReverseLimit(angle);
}

// Called repeatedly when this Command is scheduled to run
void RotateWrist::Execute() {
	double RT = oi.getAxis(RIGHT_TRIG);
	double LT = oi.getAxis(LEFT_TRIG);

	double speed = driveProfile(RT - LT);

	grabber.simpleWristControl(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool RotateWrist::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RotateWrist::End() {
	grabber.simpleWristControl(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateWrist::Interrupted() {
	grabber.simpleWristControl(0);
}

double RotateWrist::driveProfile(double input) {
	double out = maxSpeed * fabs(input);

	if(input > 0){
		return out;
	}
	if(input < 0){
		return -out;
	} else {
		return 0;
	}
}

void RotateWrist::getPreferences(){
	maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);
	angle = Preferences::GetInstance()->GetDouble("Wrist/Wrist Down Angle", 1);

	grabber.setMaxSpeed(maxSpeed);
}

void RotateWrist::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Wrist/Max Speed", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Down Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Down Angle", 0.0);
	}
}
