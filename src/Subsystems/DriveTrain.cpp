#include "DriveTrain.h"
#include "../RobotMap.h"

#include "../Commands/ArcadeDriveWithJoysticks.h"



DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	leftController(DRIVE_LEFT),
	rightController(DRIVE_RIGHT),
	driveTrain(leftController, rightController),
	Lencoder(LA_CHANNEL, LB_CHANNEL),
	Rencoder(RA_CHANNEL, RB_CHANNEL),
	gyro(SPI::Port::kOnboardCS0)
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArcadeDriveWithJoysticks);
}

void DriveTrain::arcadeDrive(double speed, double turn){
	driveTrain.ArcadeDrive(speed, turn);
}

void DriveTrain::Stop(){
	arcadeDrive(0,0);
}

<<<<<<< HEAD
double DriveTrain::getEncoderValue(encoderSide choice){
	if (choice == kLeft){
		return Lencoder.GetDistance();
	}else if(choice == kRight){
		return Rencoder.GetDistance();
	}
=======
double DriveTrain::getAngle(){
	return gyro.GetAngle();

>>>>>>> Added Gyro to DriveTrain
}
