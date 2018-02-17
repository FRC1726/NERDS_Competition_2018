#include <Commands/DriveWithJoysticks.h>
#include "../RobotMap.h"

DriveWithJoysticks::DriveWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis.get());
	Requires(&drivetrain);
	checkKeys();
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize() {
	getPreferences();

	currentSpd = 0;
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute() {
	double speed = driveProfile(oi.getAxis(LEFT_Y));
	double turn = driveProfile(oi.getAxis(RIGHT_X));
	if(speed > 0 && currentSpd >= 0){
		currentSpd = currentSpd + acceleration;
		if(currentSpd > speed){
			currentSpd = speed;
		}
	}else if(speed < 0 && currentSpd <= 0){
		currentSpd = currentSpd - acceleration;
		if(currentSpd < speed){
			currentSpd = speed;
		}
	}else{
		currentSpd = 0;
	}

	drivetrain.arcadeDrive(-currentSpd, turn);
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
	if(fabs(input) <= deadzone){
			return 0;
		}

	double out = (maxSpeed - minSpeed) * fabs(input) + minSpeed;

	if(input > 0){
		return out;
	}
	if(input < 0){
		return -out;
	} else {
		return 0;
	}
}

void DriveWithJoysticks::getPreferences() {
	//Set Drive Profile parameters
	maxSpeed = Preferences::GetInstance()->GetDouble("Joysticks/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Joysticks/Min Speed", 0.35);
	deadzone = Preferences::GetInstance()->GetDouble("Joysticks/Deadzone", .025);
	acceleration = Preferences::GetInstance()->GetDouble("Joysticks/acceleration", .025);
}

void DriveWithJoysticks::checkKeys() {
	//Drive Profile Values
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Max Speed", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Deadzone")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Deadzone", .025);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/acceleration")) {
		Preferences::GetInstance()->PutDouble("Joysticks/acceleration", 1.0);
	}
}
