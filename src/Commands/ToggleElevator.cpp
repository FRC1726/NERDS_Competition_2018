#include "ToggleElevator.h"

ToggleElevator::ToggleElevator() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
}

// Called just before this Command runs the first time
void ToggleElevator::Initialize() {
	if (grabber.getElevator() == DoubleSolenoid::kForward || grabber.getElevator() == DoubleSolenoid::kOff) {
		grabber.setElevator(DoubleSolenoid::kReverse);
	}else{
		grabber.setElevator(DoubleSolenoid::kForward);
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleElevator::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleElevator::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleElevator::Interrupted() {

}
