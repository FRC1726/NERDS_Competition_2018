#include "DeleteNetworkTables.h"
#include <networktables/NetworkTableInstance.h>


DeleteNetworkTables::DeleteNetworkTables() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DeleteNetworkTables::Initialize() {
	nt::NetworkTableInstance::GetDefault().DeleteAllEntries();
}

// Called repeatedly when this Command is scheduled to run
void DeleteNetworkTables::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DeleteNetworkTables::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DeleteNetworkTables::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeleteNetworkTables::Interrupted() {

}
