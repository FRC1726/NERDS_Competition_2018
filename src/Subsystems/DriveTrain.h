#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Talon.h>
#include <Encoder.h>
#include <VictorSP.h>

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
private:
	VictorSP leftController;
	VictorSP rightController;
	DifferentialDrive driveTrain;

	Encoder Lencoder;
	Encoder Rencoder;
  double driveProfile(double);
};

#endif  // DriveTrain_H
