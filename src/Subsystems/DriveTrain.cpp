#include "DriveTrain.h"
#include "../RobotMap.h"
#include <math.h>
#include "../Commands/ArcadeDriveWithJoysticks.h"

#include <SerialPort.h>
#include <iostream>
#include <Preferences.h>


DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	leftController(DRIVE_LEFT),
	rightController(DRIVE_RIGHT),
	driveTrain(leftController, rightController),
	Lencoder(LA_CHANNEL, LB_CHANNEL),
	Rencoder(RA_CHANNEL, RB_CHANNEL),
	gyro(SerialPort::Port::kUSB1)
{
	leftController.SetInverted(true);
	rightController.SetInverted(true);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArcadeDriveWithJoysticks);
}

void DriveTrain::arcadeDrive(double speed, double turn){
	driveTrain.ArcadeDrive(-driveProfile(speed), driveProfile(turn));
}

void DriveTrain::Stop(){
	arcadeDrive(0,0);
}

double DriveTrain::driveProfile(double input){
	if(fabs(input) <= Preferences::GetInstance()->GetDouble("Dead Zone", .025)){
		return 0;
	}
	if(input > 0)
		return (Preferences::GetInstance()->GetDouble("Max Speed", 1) - Preferences::GetInstance()->GetDouble("Min Speed", 0)) * fabs(input) + Preferences::GetInstance()->GetDouble("Min Speed", 0);
	if(input < 0)
		return -((Preferences::GetInstance()->GetDouble("Max Speed", 1) - Preferences::GetInstance()->GetDouble("Min Speed", 0)) * fabs(input) + Preferences::GetInstance()->GetDouble("Min Speed", 0));
}

double DriveTrain::getEncoderValue(encoderSide choice){
	if (choice == kLeft){
		return Lencoder.GetDistance();
	}else if(choice == kRight){
		return Rencoder.GetDistance();
	}
}

double DriveTrain::getAngle(){
	if(gyro.IsConnected())
		std::cout << "Connected!" << std::endl;
	std::cout << gyro.GetYaw() << std::endl;
	return gyro.GetYaw();

}
