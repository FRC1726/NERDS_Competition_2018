#include "CommandBase.h"

OI CommandBase::oi;
DriveTrain CommandBase::drivetrain;
Pneumatics CommandBase::pneumatics;
Grabber CommandBase::grabber;
Winch CommandBase::winch;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
