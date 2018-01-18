#include "TestGyro.h"
#include "../Subsystems/DriveTrain.h"
#include <networktables/NetworkTable.h>


TestGyro::TestGyro() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void TestGyro::Initialize() {
	NetworkTable::GetInstance()->PutNumber("Gyro Value", drivetrain->getAngle());
}

// Called repeatedly when this Command is scheduled to run
void TestGyro::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TestGyro::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TestGyro::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TestGyro::Interrupted() {

}
