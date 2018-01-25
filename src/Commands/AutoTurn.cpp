#include "AutoTurn.h"

AutoTurn::AutoTurn(double angle, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drivetrain);
	turnAngle = angle;
	maxSpeed = speed;
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
	targetAngle = drivetrain.getAngle() + turnAngle;
	drivetrain.setPidTarget(targetAngle);
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {
	double pidOut = drivetrain.getPidOut();
	if (pidOut > maxSpeed){
		pidOut = maxSpeed;
	}
	drivetrain.arcadeDrive(0,pidOut);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() {
	if (drivetrain.getAngle() == targetAngle)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void AutoTurn::End() {
	drivetrain.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {
	drivetrain.Stop();
}
