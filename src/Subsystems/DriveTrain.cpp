#include "DriveTrain.h"
#include "../RobotMap.h"
#include <math.h>
#include "../Commands/ArcadeDriveWithJoysticks.h"



DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	leftController(DRIVE_LEFT),
	rightController(DRIVE_RIGHT),
	driveTrain(leftController, rightController)
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArcadeDriveWithJoysticks);
}

void DriveTrain::arcadeDrive(double speed, double turn){
	driveTrain.ArcadeDrive(driveProfile(speed), driveProfile(turn));
}

void DriveTrain::Stop(){
	arcadeDrive(0,0);
}

double DriveTrain::driveProfile(double input){
	if(abs(input) <= DEADZONE){
		return 0;
	}
	if(input > 0)
		return (FULLSPEED - INITIALSPEED) * abs(input) + INITIALSPEED;
	if(input < 0)
		return -((FULLSPEED - INITIALSPEED) * abs(input) + INITIALSPEED);
}
