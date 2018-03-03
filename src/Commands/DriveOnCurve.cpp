#include "DriveOnCurve.h"

#include <RobotMap.h>
#include <cmath>
#include <Preferences.h>


DriveOnCurve::DriveOnCurve(PolarNum point) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	checkKeys();
	Requires(&drivetrain);
	endPoint = point;
}

// Called just before this Command runs the first time
void DriveOnCurve::Initialize() {
	getPreferences();
	double r = getVelocityRatio();
	double Vr;
	double Vl;

	if(r > 1) {
		Vr = maxVelocity / r;
		Vl = maxVelocity;
	}else if(r < 1) {
		Vr = maxVelocity;
		Vl = maxVelocity * r;
	}else{
		Vr = maxVelocity;
		Vl = maxVelocity;
	}

	drivetrain.setLeftTarget(Vl);
	drivetrain.setRightTarget(Vr);

	drivetrain.setLeftEnabled(true);
	drivetrain.setRightEnabled(true);

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
	drivetrain.setLeftEnabled(false);
	drivetrain.setRightEnabled(false);
	drivetrain.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveOnCurve::Interrupted() {
	drivetrain.setLeftEnabled(false);
	drivetrain.setRightEnabled(false);
	drivetrain.Stop();
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
	double ratio = (ROBOT_LENGTH + 2 *  r) / (ROBOT_LENGTH - 2 * r);
	return fabs(ratio);
}

void DriveOnCurve::getPreferences() {
	maxVelocity = Preferences::GetInstance()->GetDouble("Curve Drive/Max Velocity", 1.0);

	double p = Preferences::GetInstance()->GetDouble("Curve Drive/P", 0.5);
	double i = Preferences::GetInstance()->GetDouble("Curve Drive/I", 0);
	double d = Preferences::GetInstance()->GetDouble("Curve Drive/D", 0);
	double tolerance = Preferences::GetInstance()->GetDouble("Curve Drive/Max Velocity", 0.025);

	drivetrain.setLeftPID(p, i, d, tolerance);
	drivetrain.setRightPID(p, i, d, tolerance);
}

void DriveOnCurve::checkKeys() {
	if (!Preferences::GetInstance()->ContainsKey("Curve Drive/Max Velocity")) {
			Preferences::GetInstance()->PutDouble("Curve Drive/Max Velocity", 1.0);
	}

	if (!Preferences::GetInstance()->ContainsKey("Curve Drive/P")) {
			Preferences::GetInstance()->PutDouble("Curve Drive/P", 0.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Curve Drive/I")) {
			Preferences::GetInstance()->PutDouble("Curve Drive/I", 0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Curve Drive/D")) {
			Preferences::GetInstance()->PutDouble("Curve Drive/D", 0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Curve Drive/Tolerance")) {
			Preferences::GetInstance()->PutDouble("Curve Drive/Tolerance", 0.025);
	}
}
