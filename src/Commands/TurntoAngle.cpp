#include <Commands/TurntoAngle.h>
#include "RobotMap.h"

#include <Preferences.h>

TurntoAngle::TurntoAngle(double angle, double timeOut) {
	Requires(&drivetrain);
	checkKeys();

	if (timeOut > 0){
		SetTimeout(timeOut);
	}

	targetAngle = angle;
}

// Called just before this Command runs the first time
void TurntoAngle::Initialize() {
	getPreferences();
	SmartDashboard::PutNumber("Target Angle", targetAngle);

	drivetrain.setPIDRange(-maxSpeed, maxSpeed);
	drivetrain.SetPIDTarget(targetAngle);
	drivetrain.setEnabled(true);
}

// Called repeatedly when this Command is scheduled to run
void TurntoAngle::Execute() {
	double speed = drivetrain.getPIDOutput();
	SmartDashboard::PutNumber("Speed", speed);
	SmartDashboard::PutBoolean("On Target", drivetrain.onTarget());

	if(speed < minSpeed && speed > 0){
		speed = minSpeed;
	}else if(speed > -minSpeed && speed < 0){
		speed = -minSpeed;
	}

	if(drivetrain.onTarget()){
		drivetrain.Stop();
	}else{
		drivetrain.arcadeDrive(0, speed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurntoAngle::IsFinished() {
	if(IsTimedOut()){
		return true;
	}

	if (drivetrain.onTarget()){
		targetTimer.Start();
		return targetTimer.HasPeriodPassed(time);
	}else{
		targetTimer.Stop();
		targetTimer.Reset();
		return false;
	}
}

// Called once after isFinished returns true
void TurntoAngle::End() {
	drivetrain.Stop();
		drivetrain.setEnabled(false);
		targetTimer.Stop();
		targetTimer.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurntoAngle::Interrupted() {
	drivetrain.Stop();
		drivetrain.setEnabled(false);
		targetTimer.Stop();
		targetTimer.Reset();
}

void TurntoAngle::getPreferences() {
	//PID Values
	double p = Preferences::GetInstance()->GetDouble("Auto Turn/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Auto Turn/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Auto Turn/D", 0.0);
	double tolerance = Preferences::GetInstance()->GetDouble("Auto Turn/Angle Tolerance", 1.0);
	drivetrain.setPID(p, i, d, tolerance);

	//Speed Values
	maxSpeed = Preferences::GetInstance()->GetDouble("Auto Turn/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Auto Turn/Min Speed", 0.35);

	//targetTime
	time = Preferences::GetInstance()->GetDouble("Auto Turn/Target Time", 10);
}

void TurntoAngle::checkKeys() {
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
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Target Time")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Target Time", 10);
	}
}

double TurntoAngle::makeContinuous(double input){
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
