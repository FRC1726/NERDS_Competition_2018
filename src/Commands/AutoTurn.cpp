#include "AutoTurn.h"
#include <Preferences.h>

AutoTurn::AutoTurn(double angle, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drivetrain);
	turnAngle = angle;
	maxSpeed = speed;
	if (!Preferences::GetInstance()->ContainsKey("Turn P")) {
		Preferences::GetInstance()->PutDouble("Turn P", 0.1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Turn I")) {
			Preferences::GetInstance()->PutDouble("Turn I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Turn D")) {
			Preferences::GetInstance()->PutDouble("Turn D", 0.0);
	}
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
	double p = Preferences::GetInstance()->GetDouble("Turn P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Turn I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Turn D", 0.0);
	drivetrain.setPID(p, i, d);
	targetAngle = drivetrain.getAngle() + turnAngle;
	drivetrain.setPoint(targetAngle);
	drivetrain.setEnabled(true);
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
	drivetrain.setEnabled(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
}
