#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Talon.h>
#include <Encoder.h>
#include <AHRS.h>

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
private:
	Talon leftController;
	Talon rightController;
	DifferentialDrive driveTrain;
	Encoder Lencoder;
	Encoder Rencoder;
	AHRS gyro;
};

#endif  // DriveTrain_H
