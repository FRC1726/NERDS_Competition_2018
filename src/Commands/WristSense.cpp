#include <Commands/WristSense.h>

WristMovement::WristMovement() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
}

// Called just before this Command runs the first time
void WristMovement::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void WristMovement::Execute() {
	SmartDashboard::PutNumber("Sensor", grabber.getSensor());
}

// Make this return true when this Command no longer needs to run execute()
bool WristMovement::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void WristMovement::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristMovement::Interrupted() {

}
