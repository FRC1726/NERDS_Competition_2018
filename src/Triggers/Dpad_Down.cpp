#include "Dpad_Down.h"
#include "CommandBase.h"

Dpad_Down::Dpad_Down() {

}

bool Dpad_Down::Get(){
	if(CommandBase::oi.getPOV() == 180){
		return true;
	}

	return false;
}

