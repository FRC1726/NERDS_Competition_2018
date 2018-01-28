#include <Commands/DriveWithJoysticks.h>
#include "../RobotMap.h"

DriveWithJoysticks::DriveWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis.get());
	Requires(&drivetrain);
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute() {
	double speed = driveProfile(oi.getAxis(LEFT_Y));
	double turn = driveProfile(oi.getAxis(RIGHT_X));
	drivetrain.arcadeDrive(-speed, turn);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoysticks::End() {
	drivetrain.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted() {
	drivetrain.Stop();
}

double DriveWithJoysticks::driveProfile(double input) {
	if(fabs(input) <= Preferences::GetInstance()->GetDouble("Dead Zone", .025)){
			return 0;
		}

	double out = (Preferences::GetInstance()->GetDouble("Max Speed", 1) - Preferences::GetInstance()->GetDouble("Min Speed", 0)) * fabs(input) + Preferences::GetInstance()->GetDouble("Min Speed", 0);

	if(input > 0){
		return out;
	}
	if(input < 0){
		return -out;
	} else {
		return 0;
	}
}
