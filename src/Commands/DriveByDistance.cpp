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

	drivetrain.setPIDRange(-maxSpeed, maxSpeed);
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

	double turn = drivetrain.getPIDOutput();

	if(drivetrain.onTarget()){
		turn = 0;
	}else if(turn < minSpeed && turn > 0){
		turn = minSpeed;
	}else if(turn > -minSpeed && turn < 0){
		turn = -minSpeed;
	}

	if(averageDistance < targetDistance - tolerance){
		drivetrain.arcadeDrive(driveProfile(averageDistance), turn);
	}else if(averageDistance > targetDistance + tolerance){
		drivetrain.arcadeDrive(-driveProfile(averageDistance), turn);
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
	double averageDistance = (leftDistance + rightDistance)/2;

	double distanceToTarget = targetDistance - averageDistance;

	if (fabs(distanceToTarget) < tolerance){
		targetTimer.Start();
		return targetTimer.HasPeriodPassed(time);
	}else{
		targetTimer.Stop();
		targetTimer.Reset();
		return false;
	}
}

// Called once after isFinished returns true
void DriveByDistance::End() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
	targetTimer.Stop();
	targetTimer.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByDistance::Interrupted() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
	targetTimer.Stop();
	targetTimer.Reset();
}

double DriveByDistance::driveProfile(double distance) {
	if(accelDistance <= 0){
		return maxSpeed;
	}

	double initialAccel = (maxSpeed - minSpeed) * (fabs(distance)/accelDistance) + minSpeed;
	double endAccel = (maxSpeed - minSpeed) * (fabs(targetDistance - distance)/decelDistance) + minSpeed;

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
	tolerance = Preferences::GetInstance()->GetDouble("Auto Drive/Distance Tolerance", 1.0);
	double angle = Preferences::GetInstance()->GetDouble("Auto Drive/Angle Tolerance", 1.0);
	drivetrain.setPID(p, i, d, angle);

	//Set Drive Profile parameters
	maxSpeed = Preferences::GetInstance()->GetDouble("Auto Drive/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Auto Drive/Min Speed", 0.35);
	accelDistance = Preferences::GetInstance()->GetDouble("Auto Drive/Accel Distance", 12);
	decelDistance = Preferences::GetInstances()->GetDouble("Auto Drive/Decel Distance", 12);

	//Timer
	time = Preferences::GetInstance()->GetDouble("Auto Drive/Target Timer", 2.0);
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
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Distance Tolerance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Distance Tolerance", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Angle Tolerance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Angle Tolerance", 1.0);
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
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Decel Distance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Decel Distance", 12.0);
	}

	//Timer
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Target Timer")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Target Timer", 2.0);
	}
}
