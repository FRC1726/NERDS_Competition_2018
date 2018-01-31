#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics() : Subsystem("Pneumatics"),
	Grabber(PNEU_GRABBER)
{

}

void Pneumatics::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Pneumatics::GrabberOn(){
	Grabber.Set(true);
}

void Pneumatics::GrabberOff(){
	Grabber.Set(false);
}

bool Pneumatics::GetGrabberState(){
	return Grabber.Get();
}
