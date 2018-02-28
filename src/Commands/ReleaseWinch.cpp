#include "Commands/ReleaseWinch.h"

ReleaseWinch::ReleaseWinch() : CommandBase("Release Winch"){
	Requires(&winch);
}

// Called just before this Command runs the first time
void ReleaseWinch::Initialize() {
	winch.setRelease(!winch.getRelease());
}

// Called repeatedly when this Command is scheduled to run
void ReleaseWinch::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ReleaseWinch::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ReleaseWinch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseWinch::Interrupted() {

}
