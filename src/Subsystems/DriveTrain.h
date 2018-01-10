#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <RobotDrive.h>

class DriveTrain : public Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand();
	void arcadeDrive(double, double);
	void Stop();
private:
	RobotDrive driveTrain;
};

#endif  // DriveTrain_H
