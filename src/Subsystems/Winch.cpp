#include "Winch.h"
#include "../RobotMap.h"

Winch::Winch() : Subsystem("Winch"),
	release(WINCH_RELEASE),
	reel(WINCH_REEL)
{
	release.Set(true);
}

void Winch::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Winch::setRelease(bool on){
	release.Set(on);
}

bool Winch::getRelease(){
	return release.Get();
}

void Winch::Reel(double speed){
	reel.Set(speed);
}
