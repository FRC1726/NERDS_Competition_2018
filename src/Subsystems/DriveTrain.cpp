#include <Commands/DriveWithJoysticks.h>
#include "DriveTrain.h"
#include "../RobotMap.h"
#include <SerialPort.h>
#include <SmartDashboard/SmartDashboard.h>


DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	leftController(DRIVE_LEFT),
	rightController(DRIVE_RIGHT),
	drive(leftController, rightController),
	leftEncoder(LA_CHANNEL, LB_CHANNEL),
	rightEncoder(RA_CHANNEL, RB_CHANNEL),
	gyro(SerialPort::Port::kUSB1),
	pidWrite(),
	pidController(0, 0, 0, &gyro, &pidWrite)
{
	leftController.SetInverted(true);
	rightController.SetInverted(true);
	leftEncoder.SetReverseDirection(true);

	pidController.Enable();

	SmartDashboard::PutData("DriveTrain/DifferentialDrive", &drive);
	SmartDashboard::PutData("DriveTrain/Gyro", &gyro);
	SmartDashboard::PutData("DriveTrain/Left Encoder", &leftEncoder);
	SmartDashboard::PutData("DriveTrain/Right Encoder", &rightEncoder);
	SmartDashboard::PutData("DriveTrain/Gyro PID", &pidController);
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoysticks);
}

void DriveTrain::arcadeDrive(double speed, double turn){
	drive.ArcadeDrive(speed,turn);
}

void DriveTrain::Stop(){
	arcadeDrive(0,0);
}

double DriveTrain::getEncoderValue(encoderSide choice){
	if (choice == kLeft){
		return leftEncoder.GetDistance();
	}else if(choice == kRight){
		return rightEncoder.GetDistance();
	}

	return 0;
}

double DriveTrain::getAngle(){
	return gyro.GetAngle();

}

double DriveTrain::getPIDOutput(){
	return pidController.Get();
}

void DriveTrain::SetPIDTarget(double target){
	pidController.SetSetpoint(target);
}

void DriveTrain::setPID(double p,double i,double d){
	pidController.SetPID(p, i, d);
}

void DriveTrain::setEnabled(bool enabled){
	pidController.SetEnabled(enabled);
}
