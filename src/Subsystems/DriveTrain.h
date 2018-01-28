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

	//Driving
	void arcadeDrive(double, double);
	void Stop();
	double getEncoderValue(encoderSide);

	//Gyro
	double getAngle();

	//PID
	double getPIDOutput();
	void SetPIDTarget(double);
	void setPID(double, double, double);
	void setEnabled(bool);
private:
	VictorSP leftController;
	VictorSP rightController;
	DifferentialDrive drive;

	Encoder leftEncoder;
	Encoder rightEncoder;

	AHRS gyro;

	PidOut pidWrite;
	PIDController pidController;
};

#endif  // DriveTrain_H
