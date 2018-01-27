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
	gyro(SerialPort::Port::kUSB1),
	pidWrite(),
	pidcontroller(0, 0, 0, &gyro, &pidWrite)
{
	leftController.SetInverted(true);
	rightController.SetInverted(true);
	Lencoder.SetReverseDirection(true);
	pidcontroller.Enable();
	SmartDashboard::PutData("Gyro", &gyro);
	SmartDashboard::PutData("LeftEncoder", &Lencoder);
	SmartDashboard::PutData("RightEncoder", &Rencoder);
	SmartDashboard::PutData("Pid Controller", &pidcontroller);
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
	return gyro.GetAngle();

}

double DriveTrain::getPIDOutput(){
	return pidcontroller.Get();
}

void DriveTrain::setPoint(double target){
	pidcontroller.SetSetpoint(target);
}

void DriveTrain::setPID(double p,double i,double d){
	pidcontroller.SetPID(p, i, d);
}

void DriveTrain::updatSmartdashboard(){
//	SmartDashboard::PutNumber("Gyro", gyro.GetYaw());
//	SmartDashboard::PutNumber("LeftEncoder", Lencoder.GetDistance());
//	SmartDashboard::PutNumber("RightEncoder", Rencoder.GetDistance());
}
