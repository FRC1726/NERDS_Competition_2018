#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	driveTrain(DRIVE_LEFT, DRIVE_RIGHT)
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::arcadeDrive(double speed, double turn){
	driveTrain.ArcadeDrive(speed, turn);
}

void DriveTrain::Stop(){
	arcadeDrive(0,0);
}
