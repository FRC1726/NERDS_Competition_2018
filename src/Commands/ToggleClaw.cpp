#include "Commands/ToggleClaw.h"

ToggleClaw::ToggleClaw() : CommandBase("Toggle Claw") {
	Requires(&grabber);
}

// Called just before this Command runs the first time
void ToggleClaw::Initialize() {
	if (grabber.getClaw() == DoubleSolenoid::kForward || grabber.getClaw() == DoubleSolenoid::kOff) {
		grabber.setClaw(DoubleSolenoid::kReverse);
	}else{
		 grabber.setClaw(DoubleSolenoid::kForward);
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleClaw::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleClaw::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleClaw::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleClaw::Interrupted() {

}

