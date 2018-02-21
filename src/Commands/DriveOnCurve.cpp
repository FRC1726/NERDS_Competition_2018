#include "DriveOnCurve.h"

#include <RobotMap.h>
#include <cmath>

DriveOnCurve::DriveOnCurve(PolarNum point) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drivetrain);
	endPoint = point;
}

// Called just before this Command runs the first time
void DriveOnCurve::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveOnCurve::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveOnCurve::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveOnCurve::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveOnCurve::Interrupted() {

}

double DriveOnCurve::getVelocityRatio(){
	double m = endPoint.getMagnitude();
	double a = endPoint.getAngle();
	double r;
	if(a == 0){
		r = 0;
	}else{
		r = m / (2 * sin(a));
	}
	double ratio = (ROBOT_LENGTH + 2 * r) / (ROBOT_LENGTH - 2 * r);
	return ratio;
}
