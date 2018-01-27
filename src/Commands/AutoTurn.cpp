#include "AutoTurn.h"
#include <Preferences.h>

AutoTurn::AutoTurn(double angle, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drivetrain);
	turnAngle = angle;
	maxSpeed = speed;
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
	double p = Preferences::GetInstance()->GetDouble("p", 0.1);
	double i = Preferences::GetInstance()->GetDouble("i", 0.0);
	double d = Preferences::GetInstance()->GetDouble("d", 0.0);
	drivetrain.setPID(p, i, d);
	targetAngle = drivetrain.getAngle() + turnAngle;
	drivetrain.setPoint(targetAngle);
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {
	double pidOut = drivetrain.getPIDOutput();
	SmartDashboard::PutNumber("PidOut", pidOut);
	if (pidOut > maxSpeed){
		pidOut = maxSpeed;
	} else if(pidOut < -maxSpeed) {
		pidOut = -maxSpeed;
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
