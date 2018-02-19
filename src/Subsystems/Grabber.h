#ifndef Grabber_H
#define Grabber_H

#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>
#include <DoubleSolenoid.h>

class Grabber : public Subsystem {
public:
	Grabber();
	void InitDefaultCommand();

	void setMaxSpeed(double);
	void setPID(double, double, double, double);
	void setWrist(double);
	void simpleWristControl(double);
	bool getLimitSwitch();
	void SetReverseLimit(int);

	DoubleSolenoid::Value getClaw();
	void setClaw(DoubleSolenoid::Value);

	DoubleSolenoid::Value getArm();
	void setArm(DoubleSolenoid::Value);
private:
	 ctre::phoenix::motorcontrol::can::WPI_TalonSRX wrist;

	 DoubleSolenoid claw;
	 DoubleSolenoid arm;

};

#endif  // Grabber_H
