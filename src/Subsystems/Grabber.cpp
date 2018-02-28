#include "Grabber.h"
#include "../RobotMap.h"

#include "Commands/RotateWrist.h"

#include <ctre/phoenix/MotorControl/SensorCollection.h>

Grabber::Grabber() : Subsystem("Grabber"),
	wrist(WRIST_ID),
	claw(CLAW_FORWARD, CLAW_BACKWARD),
	arm(ELEVATOR_FORWARD, ELEVATOR_BACKWARD)
{
	claw.Set(DoubleSolenoid::kReverse);
	arm.Set(DoubleSolenoid::kForward);

	wrist.SetInverted(true);

	wrist.ConfigForwardLimitSwitchSource(ctre::phoenix::motorcontrol::LimitSwitchSource_FeedbackConnector, ctre::phoenix::motorcontrol::LimitSwitchNormal_NormallyOpen, WRIST_TIMEOUT);
	wrist.ConfigSetParameter(ctre::phoenix::ParamEnum::eClearPositionOnLimitF,1,0,0,WRIST_TIMEOUT);

	wrist.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, WRIST_LOOP, WRIST_TIMEOUT);
	wrist.ConfigNominalOutputForward(0, WRIST_TIMEOUT);
	wrist.ConfigNominalOutputReverse(0, WRIST_TIMEOUT);

	wrist.ConfigReverseSoftLimitEnable(true, WRIST_TIMEOUT);
}

void Grabber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RotateWrist());
}

void Grabber::setMaxSpeed(double max){
	wrist.ConfigPeakOutputForward(max, WRIST_TIMEOUT);
	wrist.ConfigPeakOutputReverse(-max, WRIST_TIMEOUT);
}
double Grabber::getWristAngle(){
	double WristAngle = wrist.GetSelectedSensorPosition(0);
	return WristAngle / 1096 * 360;
}
void Grabber::setPID(double f, double p, double i, double d){
	wrist.Config_kF(WRIST_LOOP, f, WRIST_TIMEOUT);
	wrist.Config_kP(WRIST_LOOP, p, WRIST_TIMEOUT);
	wrist.Config_kI(WRIST_LOOP, i, WRIST_TIMEOUT);
	wrist.Config_kD(WRIST_LOOP, d, WRIST_TIMEOUT);
}

void Grabber::setWrist(double target){
	target = -((4096 / 120) * target);

	wrist.Set(ctre::phoenix::motorcontrol::ControlMode::Position, target);
}

void Grabber::simpleWristControl(double spd){
	wrist.Set(spd);
}

bool Grabber::getLimitSwitch(){
	return wrist.GetSensorCollection().IsFwdLimitSwitchClosed();
}

DoubleSolenoid::Value Grabber::getClaw(){
	return claw.Get();
}

void Grabber::setClaw(DoubleSolenoid::Value state){
	claw.Set(state);
}

DoubleSolenoid::Value Grabber::getArm(){
	return arm.Get();
}

void Grabber::setArm(DoubleSolenoid::Value state){
	arm.Set(state);
}

void Grabber::SetReverseLimit(int limit){
	int target = -((4096 / 120) * limit);
	wrist.ConfigReverseSoftLimitThreshold(target, WRIST_TIMEOUT);
}

