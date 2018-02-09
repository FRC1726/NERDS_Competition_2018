#include "ReelDown.h"

ReelDown::ReelDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&winch);
	checkKeys();
}

// Called just before this Command runs the first time
void ReelDown::Initialize() {
	getPreferences();
}

// Called repeatedly when this Command is scheduled to run
void ReelDown::Execute() {
	winch.Reel(-reelSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ReelDown::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReelDown::End() {
	winch.Reel(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReelDown::Interrupted() {
	winch.Reel(0);
}

void ReelDown::getPreferences(){
	-reelSpeed = Preferences::GetInstance()->GetDouble("Reel/Speed", 0.1);
}

void ReelDown::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Reel/Speed")) {
				Preferences::GetInstance()->PutDouble("Reel/Speed", 0.1);
			}
}
