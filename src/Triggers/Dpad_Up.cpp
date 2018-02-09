#include "Dpad_Up.h"
#include "CommandBase.h"

Dpad_Up::Dpad_Up() {

}

bool Dpad_Up::Get(){
	if(CommandBase::oi.getPOV() == 0){
		return true;
	}

	return false;
}

