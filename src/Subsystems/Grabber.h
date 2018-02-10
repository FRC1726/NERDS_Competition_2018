#ifndef Grabber_H
#define Grabber_H

#include <Commands/Subsystem.h>

#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>
#include "RobotMap.h"

#include <DoubleSolenoid.h>


class Grabber : public Subsystem {
public:
	Grabber();
	void InitDefaultCommand();

	void SetMaxSpeed(double);
	void SetPID(double, double, double, double);
	void SetWrist(double);
	void SimpleWristControl(double);
	bool GetLimitSwitch();

	DoubleSolenoid::Value getClaw();
	void setClaw(DoubleSolenoid::Value);

	DoubleSolenoid::Value getElevator();
	void setElevator(DoubleSolenoid::Value);
private:
	 ctre::phoenix::motorcontrol::can::WPI_TalonSRX wrist;

	 DoubleSolenoid claw;
	 DoubleSolenoid elevator;

};

#endif  // Grabber_H
