#include "Grabber.h"
#include "../RobotMap.h"
#include <SmartDashboard/smartdashboard.h>
#include <ctre/phoenix/MotorControl/SensorCollection.h>

Grabber::Grabber() : Subsystem("Grabber"),
	wrist(WRIST_ID),
	claw(CLAW_FORWARD, CLAW_BACKWARD),
	elevator(ELEVATOR_FORWARD, ELEVATOR_BACKWARD)
{
	claw.Set(DoubleSolenoid::kReverse);
	elevator.Set(DoubleSolenoid::kForward);

	wrist.SetInverted(true);

	wrist.ConfigForwardLimitSwitchSource(ctre::phoenix::motorcontrol::LimitSwitchSource_FeedbackConnector, ctre::phoenix::motorcontrol::LimitSwitchNormal_NormallyOpen, WRIST_TIMEOUT);
	wrist.ConfigSetParameter(ctre::phoenix::ParamEnum::eClearPositionOnLimitF,1,0,0,WRIST_TIMEOUT);

	wrist.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, WRIST_LOOP, WRIST_TIMEOUT);
	wrist.ConfigNominalOutputForward(0, WRIST_TIMEOUT);
	wrist.ConfigNominalOutputReverse(0, WRIST_TIMEOUT);
}

void Grabber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Grabber::SetMaxSpeed(double max){
	wrist.ConfigPeakOutputForward(max, WRIST_TIMEOUT);
	wrist.ConfigPeakOutputReverse(-max, WRIST_TIMEOUT);
}
void Grabber::SetPID(double f, double p, double i, double d){
	wrist.Config_kF(WRIST_LOOP, f, WRIST_TIMEOUT);
	wrist.Config_kP(WRIST_LOOP, p, WRIST_TIMEOUT);
	wrist.Config_kI(WRIST_LOOP, i, WRIST_TIMEOUT);
	wrist.Config_kD(WRIST_LOOP, d, WRIST_TIMEOUT);
}

void Grabber::SetWrist(double target){
	target = -((4096 / 120) * target);
	SmartDashboard::PutNumber("Target", target);
	wrist.Set(ctre::phoenix::motorcontrol::ControlMode::Position, target);
}

void Grabber::SimpleWristControl(double spd){
	wrist.Set(spd);
}

bool Grabber::GetLimitSwitch(){
	return wrist.GetSensorCollection().IsFwdLimitSwitchClosed();
}


DoubleSolenoid::Value Grabber::getClaw(){
	return claw.Get();
}

void Grabber::setClaw(DoubleSolenoid::Value state){
	claw.Set(state);
}

DoubleSolenoid::Value Grabber::getElevator(){
	return elevator.Get();
}

void Grabber::setElevator(DoubleSolenoid::Value state){
	elevator.Set(state);
}


