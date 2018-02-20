#include <Commands/ReelUp.h>

ReelUp::ReelUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&winch);
	checkKeys();
}

// Called just before this Command runs the first time
void ReelUp::Initialize() {
	getPreferences();
}

// Called repeatedly when this Command is scheduled to run
void ReelUp::Execute() {
	winch.Reel(reelSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ReelUp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReelUp::End() {
	winch.Reel(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReelUp::Interrupted() {
	winch.Reel(0);
}

void ReelUp::getPreferences(){
	reelSpeed = Preferences::GetInstance()->GetDouble("Reel/Speed", 0.1);
}

void ReelUp::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Reel/Speed")) {
				Preferences::GetInstance()->PutDouble("Reel/Speed", 0.1);
			}
}
