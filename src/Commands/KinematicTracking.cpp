#include "KinematicTracking.h"
#include "Subsystems/DriveTrain.h"

KinematicTracking::KinematicTracking(std::pair<double, double> position, double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	currentPosition = position;
	currentAngle = angle;
}

// Called just before this Command runs the first time
void KinematicTracking::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void KinematicTracking::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool KinematicTracking::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void KinematicTracking::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KinematicTracking::Interrupted() {

}

std::pair<double, double> calculateVector() {
	double velocityRight =  drivetrain.rightEncoder;
	double velocityLeft = drivetrain.leftEncoder();
}
