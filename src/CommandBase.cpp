#include "CommandBase.h"

OI CommandBase::oi;
DriveTrain CommandBase::drivetrain;
Pneumatics CommandBase::pneumatics;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
