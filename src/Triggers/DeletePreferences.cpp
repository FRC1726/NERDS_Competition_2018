#include "DeletePreferences.h"

#include <CommandBase.h>
#include <RobotMap.h>

DeletePreferences::DeletePreferences() {

}

bool DeletePreferences::Get() const {
	return CommandBase::oi.getButtonState(BUTTON_SELECT) && CommandBase::oi.getButtonState(BUTTON_START);
}

