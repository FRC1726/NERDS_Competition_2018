#ifndef Grabber_H
#define Grabber_H

#include <Commands/Subsystem.h>

#include "ctre/Phoenix.h"
#include "RobotMap.h"

#include <DoubleSolenoid.h>


class Grabber : public Subsystem {
public:
	Grabber();
	void InitDefaultCommand();
	void SetMaxSpeed(double);
	void SetPID(double, double, double, double);
	void SetWrist(double);
	DoubleSolenoid::Value getClaw();
	void setClaw(DoubleSolenoid::Value);
	DoubleSolenoid::Value getElevator();
	void setElevator(DoubleSolenoid::Value);
private:
	 WPI_TalonSRX wrist;

	 DoubleSolenoid claw;
	 DoubleSolenoid elevator;

};

#endif  // Grabber_H
