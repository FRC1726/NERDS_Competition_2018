#include "Winch.h"
#include "../RobotMap.h"

Winch::Winch() : Subsystem("Winch"),
	release(WINCH_RELEASE),
	reel(WINCH_REEL)
{
	release.Set(false);
}

void Winch::InitDefaultCommand() {

}

void Winch::setRelease(bool on){
	release.Set(on);
}

bool Winch::getRelease(){
	return release.Get();
}

void Winch::Reel(double speed){
	reel.Set(speed);
}
