#include <Commands/DriveByDistance.h>
#include "../RobotMap.h"

#include <Preferences.h>

DriveByDistance::DriveByDistance(double target_in, double timeOut) : CommandBase("DriveStraight") {
	Requires(&drivetrain);
	checkKeys();

	if (timeOut > 0){
		SetTimeout(timeOut);
	}

	targetDistance = target_in;
	rightInitial = 0;
	leftInitial = 0;
}

// Called just before this Command runs the first time <3
void DriveByDistance::Initialize() {
	getPreferences();

	drivetrain.SetPIDTarget(drivetrain.getAngle());
	drivetrain.setEnabled(true);

	leftInitial = drivetrain.getEncoderValue(DriveTrain::kLeft);
	rightInitial = drivetrain.getEncoderValue(DriveTrain::kRight);
	averageInitialDistance = (leftInitial + rightInitial)/2;
}

// Called repeatedly when this Command is scheduled to run
void DriveByDistance::Execute() {
	double leftDistance = drivetrain.getEncoderValue(DriveTrain::kLeft) - leftInitial;
	double rightDistance = drivetrain.getEncoderValue(DriveTrain::kRight) - rightInitial;
	double averageDistance = (leftDistance + rightDistance)/2;

	if(averageDistance < targetDistance){
		drivetrain.arcadeDrive(driveProfile(averageDistance), drivetrain.getPIDOutput());
	}else if(averageDistance < targetDistance){
		drivetrain.arcadeDrive(-driveProfile(averageDistance), drivetrain.getPIDOutput());
	}else {
		drivetrain.Stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByDistance::IsFinished() {
	if (IsTimedOut()){
		return true;
	}

	double leftDistance = drivetrain.getEncoderValue(DriveTrain::kLeft) - leftInitial;
	double rightDistance = drivetrain.getEncoderValue(DriveTrain::kRight) - rightInitial;
	double averageDistance = (leftDistance = rightDistance)/2;

	double distanceToTarget = targetDistance - averageDistance;

	if (fabs(distanceToTarget) < DRIVE_TARGET){
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void DriveByDistance::End() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByDistance::Interrupted() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
}

double DriveByDistance::driveProfile(double distance) {
	if(accelDistance <= 0){
		return maxSpeed;
	}

	double initialAccel = (maxSpeed - minSpeed) * (fabs(averageInitialDistance - distance)/accelDistance) + minSpeed;
	double endAccel = (maxSpeed - minSpeed) * (1 - fabs(averageInitialDistance - distance)/accelDistance) + minSpeed;

	double speed;

	if(initialAccel <= endAccel) {
		speed = initialAccel;
	}else{
		speed = endAccel;
	}

	if(speed > maxSpeed){
		return maxSpeed;
	} else {
		return speed;
	}
}

void DriveByDistance::getPreferences() {
	//Set PID
	double p = Preferences::GetInstance()->GetDouble("Auto Drive/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Auto Drive/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Auto Drive/D", 0.0);
	drivetrain.setPID(p, i, d);

	//Set Drive Profile parameters
	maxSpeed = Preferences::GetInstance()->GetDouble("Auto Drive/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Auto Drive/Min Speed", 0.35);
	accelDistance = Preferences::GetInstance()->GetDouble("Auto Drive/Accel Distance", 12);
}

void DriveByDistance::checkKeys() {
	//PID Values
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/P")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/P", 0.1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/I")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/D")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/D", 0.0);
	}

	//Drive Profile Values
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Max Speed", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Accel Distance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Accel Distance", 12.0);
	}
}
