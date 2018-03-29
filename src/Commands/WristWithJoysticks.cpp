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

	double speed = movementProfile(RT - LT);

	double currentAngle = grabber.wristSetPoint();

	double newAngle = grabber.wristSetPoint() + speed;

	if(newAngle > angle) {
		newAngle = angle;
	}
	if(newAngle < 0) {
			newAngle = 0;
	}

	SmartDashboard::PutNumber("Wrist Setpoint", newAngle);
	SmartDashboard::PutNumber("Wrist Angle", currentAngle);

	grabber.SetWrist(newAngle);
}

// Make this return true when this Command no longer needs to run execute()
bool WristWithJoysticks::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void WristWithJoysticks::End() {
	//grabber.SimpleWristControl(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristWithJoysticks::Interrupted() {
	//grabber.SimpleWristControl(0);
}

void WristWithJoysticks::getPreferences(){
	maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);
	angle = Preferences::GetInstance()->GetDouble("Wrist/Wrist Down Angle", 1);
	deadzone = Preferences::GetInstance()->GetDouble("Wrist/Deadzone", 0.025);

	double p = Preferences::GetInstance()->GetDouble("Wrist/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Wrist/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Wrist/D", 0.0);
	double f = Preferences::GetInstance()->GetDouble("Wrist/F", 0.0);

	grabber.SetPID(f, p, i, d);

	grabber.SetMaxSpeed(1);
}

void WristWithJoysticks::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Wrist/Max Speed", 1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Down Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Down Angle", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Deadzone")) {
			Preferences::GetInstance()->PutDouble("Wrist/Deadszone", 0.025);
	}
}

double WristWithJoysticks::movementProfile(double input) {
	if(fabs(input) <= deadzone){
			return 0;
		}

	double out = (maxSpeed) * fabs(input);

	if(input > 0){
		return out;
	}
	if(input < 0){
		return -out;
	} else {
		return 0;
	}
}
