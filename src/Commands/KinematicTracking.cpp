#include "KinematicTracking.h"
#include "RobotMap.h"
#include <cmath>


KinematicTracking::KinematicTracking(std::pair<double, double> position, double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	currentPosition = position;
	currentAngle = angle;
}

// Called just before this Command runs the first time
void KinematicTracking::Initialize() {
	timer.Reset();
	timer.Start();
	previousTime = timer.Get();
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
	timer.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KinematicTracking::Interrupted() {
	timer.Reset();
}

std::pair<double, double> KinematicTracking::calculateVector() {
	double velocityRight = drivetrain.getVelocity(DriveTrain::kRight);
	double velocityLeft = drivetrain.getVelocity(DriveTrain::kLeft);
	double theta = ((velocityRight - velocityLeft) / ROBOT_LENGTH) * getTime();
	double turnRadius = ((velocityLeft + velocityRight)/(velocityRight - velocityLeft)) * 0.5;
	double mag = turnRadius / sin(theta/2);
	return std::make_pair(mag,theta);

}

double KinematicTracking::getTime() {
	double currentTime = timer.Get();

	double difference = currentTime - previousTime;
	previousTime = currentTime;

	return difference;
}
