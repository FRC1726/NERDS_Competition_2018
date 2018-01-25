#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Encoder.h>
#include <AHRS.h>
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
	double getAngle();
	void updatSmartdashboard();
private:
	VictorSP leftController;
	VictorSP rightController;
	DifferentialDrive driveTrain;

	Encoder Lencoder; // display this
	Encoder Rencoder; // display this
	AHRS gyro; // display this
  double driveProfile(double);

};

#endif  // DriveTrain_H
