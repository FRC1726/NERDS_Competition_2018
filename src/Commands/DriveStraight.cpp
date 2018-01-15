#include "DriveStraight.h"
#include "Robot.hpp"

DriveStraight::DriveStraight(double speed_in, double target_in, double TimeOut = 0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	if (TimeOut > 0){
		SetTimeout(TimeOut);
	}
	Requires(Robot::drivetrain.get());
	speed = speed_in;
	target = target_in;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	Leftinitial = Robot::drivetrain->getEncoderValue(DriveTrain::kLeft);
	Rightinitial = Robot::drivetrain->getEncoderValue(DriveTrain::kRight);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	double currentLeft = Robot::drivetrain->getEncoderValue(DriveTrain::kLeft);
	if (currentLeft > (Leftinitial + target)){
		Robot::drivetrain->arcadeDrive(-speed, 0);
	}else if (currentLeft < (Leftinitial + target)){
		Robot::drivetrain->arcadeDrive(speed, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	if (IsTimedOut()){
		return true;
	}

	double currentLeft = Robot::drivetrain->getEncoderValue(DriveTrain::kLeft);
	double currentRight = Robot::drivetrain->getEncoderValue(DriveTrain::kRight);
	if (currentLeft == (Leftinitial + target)){
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void DriveStraight::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	Robot::drivetrain->Stop();
}
