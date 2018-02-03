#include "Grabber.h"
#include "../RobotMap.h"
#include <SmartDashboard/smartdashboard.h>

#include "Commands/WristSense.h"


Grabber::Grabber() : Subsystem("ExampleSubsystem"),
	wrist(WRIST_ID)
{

//	int absolutePosition = wrist.GetSelectedSensorPosition(0) & 0xFFF;
//	wrist.SetSelectedSensorPosition(absolutePosition, WRIST_LOOP, WRIST_TIMEOUT);
	wrist.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, WRIST_LOOP, WRIST_TIMEOUT);
	wrist.ConfigNominalOutputForward(0, WRIST_TIMEOUT);
	wrist.ConfigNominalOutputReverse(0, WRIST_TIMEOUT);
}

void Grabber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new WristMovement);
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
	target = (4096 / 360) * target;
	SmartDashboard::PutNumber("Target", target);
	wrist.Set(ControlMode::Position, target);

}

double Grabber::getSensor() {
	return wrist.GetSelectedSensorPosition(0);
}
