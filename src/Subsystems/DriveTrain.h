#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Talon.h>
#include <Encoder.h>

class DriveTrain : public Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand();
	void arcadeDrive(double, double);
	void Stop();
private:
	Talon leftController;
	Talon rightController;
	DifferentialDrive driveTrain;
	Encoder Lencoder;
	Encoder Rencoder;
};

#endif  // DriveTrain_H
