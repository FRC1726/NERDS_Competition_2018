#include <Commands/ToggleGrabber.h>
#include "../RobotMap.h"

ToggleGrabber::ToggleGrabber() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&pneumatics);
}

// Called just before this Command runs the first time
void ToggleGrabber::Initialize() {
	if (pneumatics.GetGrabberState()) {
		pneumatics.GrabberOff();
	}else{
		 pneumatics.GrabberOn();
	}

}

// Called repeatedly when this Command is scheduled to run
void ToggleGrabber::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleGrabber::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleGrabber::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleGrabber::Interrupted() {

}

