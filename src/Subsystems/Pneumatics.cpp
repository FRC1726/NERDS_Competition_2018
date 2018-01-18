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

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Pneumatics::GrabberOn(){
	Grabber.Set(true);
}
void Pneumatics::GrabberOff(){
	Grabber.Set(false);
}
bool Pneumatics::GetGrabberState(){
	return Grabber.Get();
}
