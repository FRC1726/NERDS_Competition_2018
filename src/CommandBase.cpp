#include "CommandBase.h"

#include <Commands/Scheduler.h>

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
DriveTrain CommandBase::drivetrain;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
