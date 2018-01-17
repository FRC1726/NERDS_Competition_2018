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
<<<<<<< HEAD
	double getEncoderValue(encoderSide);
=======
	double getAngle();
>>>>>>> Added Gyro to DriveTrain
private:
	Talon leftController;
	Talon rightController;
	DifferentialDrive driveTrain;
<<<<<<< HEAD
	Encoder Lencoder;
	Encoder Rencoder;
=======
	AHRS gyro;
>>>>>>> Added Gyro to DriveTrain
};

#endif  // DriveTrain_H
