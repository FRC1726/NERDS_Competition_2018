#include "CommandBase.h"

#include <Commands/Scheduler.h>

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
std::unique_ptr<DriveTrain> CommandBase::drivetrain = std::make_unique<DriveTrain>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
