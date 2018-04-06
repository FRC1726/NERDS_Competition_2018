#include "AutoWrist.h"

AutoWrist::AutoWrist(double degrees) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
	angle = degrees;
}

// Called just before this Command runs the first time
void AutoWrist::Initialize() {
	getPreferences();
	grabber.SetWrist(angle);
}

// Called repeatedly when this Command is scheduled to run
void AutoWrist::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoWrist::IsFinished() {
	double wristRange = Preferences::GetInstance()->GetDouble("Wrist/Wrist Angle Range", 0.1);

	return (grabber.getWristAngle() >= (angle - wristRange)) && (grabber.getWristAngle() <= (angle + wristRange));
}

// Called once after isFinished returns true
void AutoWrist::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoWrist::Interrupted() {

}

void AutoWrist::getPreferences() {
	double p = Preferences::GetInstance()->GetDouble("Wrist/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Wrist/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Wrist/D", 0.0);
	double f = Preferences::GetInstance()->GetDouble("Wrist/F", 1);

	double maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);

	grabber.SetPID(f, p, i, d);
	grabber.SetMaxSpeed(maxSpeed);
}
