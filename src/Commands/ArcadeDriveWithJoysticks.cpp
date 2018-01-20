#include "ArcadeDriveWithJoysticks.h"
#include "../RobotMap.h"
#include "../Robot.hpp"

ArcadeDriveWithJoysticks::ArcadeDriveWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void ArcadeDriveWithJoysticks::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArcadeDriveWithJoysticks::Execute() {
	drivetrain->arcadeDrive(oi->getAxis(LEFT_Y), oi->getAxis(RIGHT_X));
}

// Make this return true when this Command no longer needs to run execute()
bool ArcadeDriveWithJoysticks::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArcadeDriveWithJoysticks::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArcadeDriveWithJoysticks::Interrupted() {
	drivetrain->Stop();
}
