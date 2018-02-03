#ifndef Grabber_H
#define Grabber_H

#include <Commands/Subsystem.h>

#include "ctre/Phoenix.h"
#include "RobotMap.h"



class Grabber : public Subsystem {
public:
	Grabber();
	void InitDefaultCommand();
	void SetMaxSpeed(double);
	void SetPID(double, double, double, double);
	void SetWrist(double);
	double getSensor();
private:
	 WPI_TalonSRX wrist;

};

#endif  // Grabber_H
