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
	double getPidOut();
	void setPidTarget(double);
private:
	VictorSP leftController;
	VictorSP rightController;
	DifferentialDrive driveTrain;

	Encoder Lencoder;
	Encoder Rencoder;
	AHRS gyro;
	PidOut pidWrite;
	PIDController pid;
  double driveProfile(double);

};

#endif  // DriveTrain_H
