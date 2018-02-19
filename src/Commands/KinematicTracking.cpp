#include "KinematicTracking.h"
#include "RobotMap.h"
#include <cmath>
#include <SmartDashboard/SmartDashboard.h>


KinematicTracking::KinematicTracking(PolarNum position, double angle){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	currentPosition = position;
	currentAngle = angle;
}

KinematicTracking::KinematicTracking(Cartesian position, double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	currentPosition = position.toPolar();
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
	PolarNum posChange = calculateVector();
	SmartDashboard::PutNumber("Tracking/Test/PosChangeX", posChange.toCartesian().getX());
	SmartDashboard::PutNumber("Tracking/Test/PosChangeY", posChange.toCartesian().getY());
	currentPosition = currentPosition + posChange;
	double angleChange = calculateAngle();
	SmartDashboard::PutNumber("Tracking/Test/AngleChange", angleChange);
	currentAngle += angleChange;

	SmartDashboard::PutNumber("Tracking/X", currentPosition.toCartesian().getX());
	SmartDashboard::PutNumber("Tracking/Y", currentPosition.toCartesian().getY());
	SmartDashboard::PutNumber("Tracking/Angle", currentAngle);
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

PolarNum KinematicTracking::calculateVector() {
	double velocityRight = drivetrain.getVelocity(DriveTrain::kRight);
	double velocityLeft = drivetrain.getVelocity(DriveTrain::kLeft);
	SmartDashboard::PutNumber("Tracking/Test/VR", velocityRight);
	SmartDashboard::PutNumber("Tracking/Test/VL", velocityLeft);
	double theta = ((velocityRight - velocityLeft) / ROBOT_LENGTH) * getTime();
	double angle = theta / 2;
	SmartDashboard::PutNumber("Tracking/Test/Theta", angle);
	double turnRadius;
	if(velocityRight == velocityLeft){
		turnRadius = 0;
	}else{
		turnRadius = ((velocityLeft + velocityRight)/(velocityRight - velocityLeft)) * 0.5;
	}
	SmartDashboard::PutNumber("Tracking/Test/TurnRadius", turnRadius);
	double mag;
	if(angle == 0){
		mag = 0;
	}else{
		mag = turnRadius / sin(angle);
	}
	SmartDashboard::PutNumber("Tracking/Test/mag", mag);

	PolarNum out(mag, angle * 180 / 3.14159);
	return out;
}

double KinematicTracking::calculateAngle(){
	double velocityRight = drivetrain.getVelocity(DriveTrain::kRight);
	double velocityLeft = drivetrain.getVelocity(DriveTrain::kLeft);
	double theta = ((velocityRight - velocityLeft) / ROBOT_LENGTH) * getTime();
	return theta * 180 / 3.14159;
}

double KinematicTracking::getTime() {
	double currentTime = timer.Get();

	double difference = currentTime - previousTime;
	previousTime = currentTime;
	SmartDashboard::PutNumber("Tracking/Test/Time", difference);

	return difference;
}
