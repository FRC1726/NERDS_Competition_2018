#include "DriveStraight.h"

DriveStraight::DriveStraight(double speed_in, double target_in) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
	speed = speed_in;
	target = target_in;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	if(position == target){
		return true;
	}else {
		return false;
	}

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
