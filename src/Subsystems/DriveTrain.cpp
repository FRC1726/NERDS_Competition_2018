#include "DriveTrain.h"
#include "../RobotMap.h"

#include "Commands/DriveWithJoysticks.h"
#include "NERDS/PidOut.h"
#include "NERDS/PidIn.h"

#include <SerialPort.h>
#include <SmartDashboard/SmartDashboard.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	leftController(DRIVE_LEFT),
	rightController(DRIVE_RIGHT),
	drive(leftController, rightController),
	leftEncoder(LA_CHANNEL, LB_CHANNEL),
	rightEncoder(RA_CHANNEL, RB_CHANNEL),
	left(0,0,0, new PidIn(std::bind(&frc::Encoder::GetRate, &leftEncoder)), &leftController),
	right(0,0,0, new PidIn(std::bind(&frc::Encoder::GetRate, &rightEncoder)), &rightController),
	gyro(SerialPort::Port::kUSB1),
	pidController(0, 0, 0, &gyro, new PidOut<void>())
{
	leftEncoder.SetReverseDirection(true);
	leftEncoder.SetDistancePerPulse(6 * 3.141592/1440);
	rightEncoder.SetDistancePerPulse(6 * 3.141592/1440);

	pidController.SetInputRange(-180, 180);
	pidController.SetOutputRange(0,1);
	pidController.SetContinuous(true);

	left.SetOutputRange(-1,1);
	right.SetOutputRange(-1,1);

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
	return gyro.GetYaw();

}

double DriveTrain::getPIDOutput(){
	return pidController.Get();
}

void DriveTrain::SetPIDTarget(double target){
	pidController.SetSetpoint(target);
}

void DriveTrain::setPID(double p,double i,double d,double tolerance){
	pidController.SetPID(p, i, d);
	pidController.SetAbsoluteTolerance(tolerance);
}

void DriveTrain::setEnabled(bool enabled){
	pidController.SetEnabled(enabled);
}

void DriveTrain::setPIDRange(double min,double max){
	pidController.SetOutputRange(min, max);
}
bool DriveTrain::onTarget(){
	return pidController.OnTarget();
}

double DriveTrain::getVelocity(encoderSide choice){
	if (choice == kLeft){
		return leftEncoder.GetRate();
	}else if (choice == kRight ){
		return rightEncoder.GetRate();
	}

	return 0;
}

void DriveTrain::setLeftTarget(double target){
	left.SetSetpoint(target);
}

void DriveTrain::setLeftPID(double p,double i,double d,double tolerance){
	left.SetPID(p, i, d);
	left.SetAbsoluteTolerance(tolerance);
}

void DriveTrain::setLeftEnabled(bool enabled){
	left.SetEnabled(enabled);
}
bool DriveTrain::onTargetLeft(){
	return left.OnTarget();
}
void DriveTrain::setRightTarget(double target){
	right.SetSetpoint(target);
}

void DriveTrain::setRightPID(double p, double i, double d, double tolerance){
	right.SetPID(p, i, d);
	right.SetAbsoluteTolerance(tolerance);
}

void DriveTrain::setRightEnabled(bool enabled){
	right.SetEnabled(enabled);
}
bool DriveTrain::onTargetRight(){
	return right.OnTarget();
}
