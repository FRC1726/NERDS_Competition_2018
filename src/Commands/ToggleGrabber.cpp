#include <Commands/ToggleGrabber.h>
#include "../RobotMap.h"

ToggleGrabber::ToggleGrabber() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(pneumatics.get());
}

// Called just before this Command runs the first time
void ToggleGrabber::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleGrabber::Execute() {
	pneumatics->(Commands::Pneumatics->GetGrabberState());
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleGrabber::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleGrabber::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleGrabber::Interrupted() {

}
