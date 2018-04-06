#include <Commands/InitWrist.h>
#include <SmartDashboard/SmartDashboard.h>

InitWrist::InitWrist() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
	SetRunWhenDisabled(false);
	SetInterruptible(false);
}

// Called just before this Command runs the first time
void InitWrist::Initialize() {
	getPreferences();
	grabber.SimpleWristControl(maxSpeed);
}

// Called repeatedly when this Command is scheduled to run
void InitWrist::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool InitWrist::IsFinished() {
	SmartDashboard::PutBoolean("Limit Switch", grabber.GetLimitSwitch());
	return grabber.GetLimitSwitch();
}

// Called once after isFinished returns true
void InitWrist::End() {
	//grabber.SimpleWristControl(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InitWrist::Interrupted() {
	//grabber.SimpleWristControl(0);
}

void InitWrist::getPreferences(){
	maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);
}
