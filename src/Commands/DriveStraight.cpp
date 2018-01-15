#include "DriveStraight.h"

DriveStraight::DriveStraight(double speed_in, double target_in, double TimeOut = 0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	if (TimeOut > 0){
		SetTimeout(TimeOut);
	}
	Requires(drivetrain.get());
	speed = speed_in;
	target = target_in;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	Leftinitial = drivetrain->getEncoderValue(DriveTrain::kLeft);
	rightinitial = drivetrain->getEncoderValue(DriveTrain::kRight);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	double curentLeft = drivetrain->getEncoderValue(DriveTrain::kLeft);
	if (currentLeft > (Leftinitial + target)){
		drivetrain->arcadeDrive(-speed, 0);
	}else if (currentleft < (Leftinitial + target)){
		drivetrain->arcadeDrive(speed, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	if (IsTimedOut()){
		return true;
	}

	double curentLeft = drivetrain->getEncoderValue(DriveTrain::kLeft);
	double currentRight = drivetrain->getEncoderValue(DriveTrain::kRight);
	if (currentLeft == (Leftinitial + target)){
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void DriveStraight::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	drivetrain->Stop();
}
