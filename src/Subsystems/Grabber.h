#ifndef Grabber_H
#define Grabber_H

#include <Commands/Subsystem.h>

#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>
#include "RobotMap.h"

#include <Solenoid.h>


class Grabber : public Subsystem {
public:
	Grabber();
	void InitDefaultCommand();
	void SetMaxSpeed(double);
	void SetPID(double, double, double, double);
	void SetWrist(double);
	bool getClaw();
	void setClaw(bool);
	bool getElevator();
	void setElevator(bool);
private:
	 ctre::phoenix::motorcontrol::can::WPI_TalonSRX wrist;

	 frc::Solenoid claw;
	 frc::Solenoid elevator;

};

#endif  // Grabber_H
