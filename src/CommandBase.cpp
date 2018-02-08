#include "CommandBase.h"

OI CommandBase::oi;
DriveTrain CommandBase::drivetrain;
Grabber CommandBase::grabber;
Winch CommandBase::winch;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
