#include "WristUp.h"

#include <Preferences.h>

WristUp::WristUp() : CommandBase("Wrist Up") {
	Requires(&grabber);
	checkKeys();
}

// Called just before this Command runs the first time
void WristUp::Initialize() {
	getPreferences();
	grabber.setWrist(angle);
}

// Called repeatedly when this Command is scheduled to run
void WristUp::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WristUp::IsFinished() {
	double wristRange = Preferences::GetInstance()->GetDouble("Wrist/Wrist Angle Range", 0.1);

	return (grabber.getWristAngle() >= (angle - wristRange)) && (grabber.getWristAngle() <= (angle + wristRange));
}

// Called once after isFinished returns true
void WristUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristUp::Interrupted() {

}

void WristUp::getPreferences(){
	double p = Preferences::GetInstance()->GetDouble("Wrist/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Wrist/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Wrist/D", 0.0);
	double f = Preferences::GetInstance()->GetDouble("Wrist/F", 0.0);

	double maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);

	angle = Preferences::GetInstance()->GetDouble("Wrist/Wrist Up Angle", 1);

	grabber.setPID(f, p, i, d);
	grabber.setMaxSpeed(maxSpeed);
}

void WristUp::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Wrist/P")) {
		Preferences::GetInstance()->PutDouble("Wrist/P", 0.1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/I")) {
		Preferences::GetInstance()->PutDouble("Wrist/I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/D")) {
		Preferences::GetInstance()->PutDouble("Wrist/D", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/F")) {
		Preferences::GetInstance()->PutDouble("Wrist/F", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Wrist/Max Speed", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Up Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Up Angle", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Angle Range")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Angle Range", 2.5);
	}
}
