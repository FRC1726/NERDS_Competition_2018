#include "DriveStraight.h"

DriveStraight::DriveStraight(double speed_in, double target_in, double TimeOut = 0) : CommandBase("DriveStraight") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis.get());
	if (TimeOut > 0){
		SetTimeout(TimeOut);
	}
	Requires(&drivetrain);
	speed = speed_in;
	distance = target_in;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	double p = Preferences::GetInstance()->GetDouble("p", 0.1);
	double i = Preferences::GetInstance()->GetDouble("i", 0.0);
	double d = Preferences::GetInstance()->GetDouble("d", 0.0);
	drivetrain.setPID(p, i, d);
	drivetrain.setPoint(drivetrain.getAngle() );
	Leftinitial = drivetrain.getEncoderValue(DriveTrain::kLeft);
	Rightinitial = drivetrain.getEncoderValue(DriveTrain::kRight);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	SmartDashboard::PutNumber("TurnValue", drivetrain.getPIDOutput());
	double currentLeft = drivetrain.getEncoderValue(DriveTrain::kLeft);
	if (currentLeft > (Leftinitial + distance)){
		drivetrain.arcadeDrive(-speed, drivetrain.getPIDOutput());
	}else if (currentLeft < (Leftinitial + distance)){
		drivetrain.arcadeDrive(speed, drivetrain.getPIDOutput());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	if (IsTimedOut()){
		return true;
	}

	double currentLeft =drivetrain.getEncoderValue(DriveTrain::kLeft);
	double currentRight = drivetrain.getEncoderValue(DriveTrain::kRight);
	if (currentLeft > (Leftinitial + distance) - 4 && currentLeft < (Leftinitial + distance) + 4){
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void DriveStraight::End() {
	drivetrain.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	drivetrain.Stop();
}

double DriveStraight::DriveProfile(double input){
	double current = drivetrain.getEncoderValue(DriveTrain::kRight);
	double dist = current + Preferences::GetInstance()->GetDouble("AccelDistance", 5);
	double target = drivetrain.getEncoderValue(DriveTrain::kRight) + distance;
	double min = Preferences::GetInstance()->GetDouble("Min Speed", 0);
	double max = Preferences::GetInstance()->GetDouble("Max Speed", 0);
	double out = (max - min) + current/dist + min;

	if(current <= dist){
		return out;
	}else if(current <= target - dist){
		return max;
	}else if(current <= target){
		return max;
	}else{
		return -max;
	}
}
