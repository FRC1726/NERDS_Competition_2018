#include <Commands/ToggleArm.h>

ToggleArm::ToggleArm() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
}

// Called just before this Command runs the first time
void ToggleArm::Initialize() {
	if (grabber.getArm() == DoubleSolenoid::kForward || grabber.getArm() == DoubleSolenoid::kOff) {
		grabber.setArm(DoubleSolenoid::kReverse);
	}else{
		grabber.setArm(DoubleSolenoid::kForward);
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleArm::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleArm::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleArm::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleArm::Interrupted() {

}
