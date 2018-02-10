#include <Commands/InitClaw.h>
#include <smartdashboard/SmartDashboard.h>

InitClaw::InitClaw() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
	checkKeys();
	SetRunWhenDisabled(true);
	SetInterruptible(false);
}

// Called just before this Command runs the first time
void InitClaw::Initialize() {
	getPreferences();
	grabber.SimpleWristControl(maxSpeed);
}

// Called repeatedly when this Command is scheduled to run
void InitClaw::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool InitClaw::IsFinished() {
	SmartDashboard::PutBoolean("Limit Switch", grabber.GetLimitSwitch());
	return grabber.GetLimitSwitch();
}

// Called once after isFinished returns true
void InitClaw::End() {
	grabber.SimpleWristControl(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InitClaw::Interrupted() {
	grabber.SimpleWristControl(0);
}

void InitClaw::getPreferences(){
	maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);
}

void InitClaw::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Wrist/Max Speed", 0.0);
	}
}
