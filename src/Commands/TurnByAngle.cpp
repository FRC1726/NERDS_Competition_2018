#include <Commands/TurnByAngle.h>
#include "RobotMap.h"

#include <Preferences.h>

TurnByAngle::TurnByAngle(double angle, double timeOut) {
	Requires(&drivetrain);
	checkKeys();

	if (timeOut > 0){
		SetTimeout(timeOut);
	}

	targetAngle = 0;
	turnAngle = makeContinuous(angle);
}

// Called just before this Command runs the first time
void TurnByAngle::Initialize() {
	getPreferences();
	targetAngle = makeContinuous(drivetrain.getAngle() + turnAngle);

	drivetrain.setPIDRange(minSpeed, maxSpeed);
	drivetrain.SetPIDTarget(targetAngle);
	drivetrain.setEnabled(true);
}

// Called repeatedly when this Command is scheduled to run
void TurnByAngle::Execute() {
	double speed = drivetrain.getPIDOutput();

	if(drivetrain.onTarget()){
		drivetrain.Stop();
	}else{
		drivetrain.arcadeDrive(0, speed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnByAngle::IsFinished() {
	if(IsTimedOut()){
		return true;
	}

	return drivetrain.onTarget();
}

// Called once after isFinished returns true
void TurnByAngle::End() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnByAngle::Interrupted() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
}

void TurnByAngle::getPreferences() {
	//PID Values
	double p = Preferences::GetInstance()->GetDouble("Auto Turn/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Auto Turn/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Auto Turn/D", 0.0);
	double tolerance = Preferences::GetInstance()->GetDouble("Auto Turn/Angle Tolerance", 1.0);
	drivetrain.setPID(p, i, d, tolerance);

	//Speed Values
	maxSpeed = Preferences::GetInstance()->GetDouble("Auto Turn/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Auto Turn/Min Speed", 0.35);
}

void TurnByAngle::checkKeys() {
	//PID Values
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/P")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/P", 0.1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/I")) {
			Preferences::GetInstance()->PutDouble("Auto Turn/I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/D")) {
			Preferences::GetInstance()->PutDouble("Auto Turn/D", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Angle Tolerance")) {
			Preferences::GetInstance()->PutDouble("Auto Turn/Angle Tolerance", 1.0);
	}

	//Turn Speeds
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Max Speed", 1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Min Speed")) {
			Preferences::GetInstance()->PutDouble("Auto Turn/Min Speed", 0.35);
	}
}

double TurnByAngle::makeContinuous(double input){
	double clippedInput = std::fmod(input, 360);
	if (clippedInput > 180){
		double angle = std::fmod(clippedInput, 180);
		return angle - 180;
	}else if(clippedInput < -180){
		double angle = std::fmod(clippedInput, 180);
		return angle + 180;
	}else{
		return clippedInput;
	}
}
