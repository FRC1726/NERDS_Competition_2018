#include "CommandBase.h"

OI CommandBase::oi;
DriveTrain CommandBase::drivetrain;
Grabber CommandBase::grabber;
Winch CommandBase::winch;
std::unique_ptr<PowerDistributionPanel> CommandBase::pdp = std::make_unique<PowerDistributionPanel>(1);

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
