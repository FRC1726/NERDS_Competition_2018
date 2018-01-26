#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Encoder.h>
#include <AHRS.h>
#include <VictorSP.h>
#include <PIDController.h>
#include "NERDS/PidOut.h"


class DriveTrain : public Subsystem {
public:
	enum encoderSide{
		kLeft,
		kRight
	};
	DriveTrain();
	void InitDefaultCommand();
	void arcadeDrive(double, double);
	void Stop();
	double getEncoderValue(encoderSide);
	double getAngle();
	double getPIDOutput();
	void setPoint(double);
	void setPID(double, double, double);
	void updatSmartdashboard();
private:
	VictorSP leftController;
	VictorSP rightController;
	DifferentialDrive driveTrain;

	Encoder Lencoder;
	Encoder Rencoder;

	AHRS gyro;
  
	PidOut pidWrite;
	PIDController pidcontroller;

	double driveProfile(double);
};

#endif  // DriveTrain_H
