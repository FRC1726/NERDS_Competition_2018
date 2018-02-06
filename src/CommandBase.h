#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Grabber.h"
#include "Subsystems/Winch.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	// Create a single static instance of all of your subsystems
	static OI oi;
	static DriveTrain drivetrain;
	static Pneumatics pneumatics;
	static Grabber grabber;
	static Winch winch;
};

#endif  // COMMAND_BASE_H
