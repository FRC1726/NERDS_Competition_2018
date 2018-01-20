#include "CommandBase.h"

#include <Commands/Scheduler.h>

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
DriveTrain CommandBase::drivetrain;
std::unique_ptr<Pneumatics> CommandBase::pneumatics = std::make_unique<Pneumatics>();
nt::NetworkTableInstance CommandBase::networktables = nt::NetworkTableInstance::GetDefault();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
