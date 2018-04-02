#include "Wait.h"

using namespace nerd;

Wait::Wait(double seconds) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	if(seconds > 0){
		SetTimeout(seconds);
	}
}

// Called just before this Command runs the first time
void Wait::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Wait::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Wait::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Wait::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Wait::Interrupted() {

}
