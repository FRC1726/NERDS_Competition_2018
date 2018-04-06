#include "WristDown.h"
#include <Preferences.h>

WristDown::WristDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
}

// Called just before this Command runs the first time
void WristDown::Initialize() {
	getPreferences();
	grabber.SetWrist(angle);
}

// Called repeatedly when this Command is scheduled to run
void WristDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WristDown::IsFinished() {
	double wristRange = Preferences::GetInstance()->GetDouble("Wrist/Wrist Angle Range", 0.1);

	return (grabber.getWristAngle() >= (angle - wristRange)) && (grabber.getWristAngle() <= (angle + wristRange));
}

// Called once after isFinished returns true
void WristDown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristDown::Interrupted() {

}

void WristDown::getPreferences(){
	double p = Preferences::GetInstance()->GetDouble("Wrist/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Wrist/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Wrist/D", 0.0);
	double f = Preferences::GetInstance()->GetDouble("Wrist/F", 0.0);

	double maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);

	angle = Preferences::GetInstance()->GetDouble("Wrist/Wrist Down Angle", 1);

	grabber.SetPID(f, p, i, d);
	grabber.SetMaxSpeed(maxSpeed);
}
