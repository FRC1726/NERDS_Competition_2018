#include "ArcadeDriveWithJoysticks.h"
#include "../RobotMap.h"
#include "../Robot.hpp"

ArcadeDriveWithJoysticks::ArcadeDriveWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis.get());
	Requires(&drivetrain);
}

// Called just before this Command runs the first time
void ArcadeDriveWithJoysticks::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArcadeDriveWithJoysticks::Execute() {
	double speed = driveProfile(oi->getAxis(LEFT_Y));
	double turn = driveProfile(oi->getAxis(RIGHT_X));
	drivetrain.arcadeDrive(speed, turn);
}

// Make this return true when this Command no longer needs to run execute()
bool ArcadeDriveWithJoysticks::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArcadeDriveWithJoysticks::End() {
	drivetrain.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArcadeDriveWithJoysticks::Interrupted() {
	drivetrain.Stop();
}

double ArcadeDriveWithJoysticks::driveProfile(double input) {
	if(fabs(input) <= Preferences::GetInstance()->GetDouble("Dead Zone", .025)){
			return 0;
		}
		if(input > 0)
			return (Preferences::GetInstance()->GetDouble("Max Speed", 1) - Preferences::GetInstance()->GetDouble("Min Speed", 0)) * fabs(input) + Preferences::GetInstance()->GetDouble("Min Speed", 0);
		if(input < 0)
			return -((Preferences::GetInstance()->GetDouble("Max Speed", 1) - Preferences::GetInstance()->GetDouble("Min Speed", 0)) * fabs(input) + Preferences::GetInstance()->GetDouble("Min Speed", 0));

}
