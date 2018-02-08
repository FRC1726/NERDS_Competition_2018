#include "Robot.h"

#include <Commands/Scheduler.h>
#include <Preferences.h>
#include<SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>

#include "CommandGroups/ForwardAndTurn.h"
#include "CommandGroups/GrabAndReturn.h"
#include <string>
#include <iostream>

void Robot::RobotInit(){
	chooser.AddDefault("ForwardBack", std::make_shared<ForwardAndTurn>());
	chooser.AddObject("Grab and Return", std::make_shared<GrabAndReturn>());

	initialPosition.AddDefault("Left", 1);
	initialPosition.AddObject("Middle", 2);
	initialPosition.AddObject("Right", 3);

	SmartDashboard::PutData("Auto Modes", &chooser);
	SmartDashboard::PutData("Position", &initialPosition);
	if(!Preferences::GetInstance()->ContainsKey("FarTarget")){
		Preferences::GetInstance()->PutBoolean("FarTarget", false);
	}
	if(!Preferences::GetInstance()->ContainsKey("Scale")){
		Preferences::GetInstance()->PutBoolean("Scale", false);
	}
	if(!Preferences::GetInstance()->ContainsKey("Switch")){
		Preferences::GetInstance()->PutBoolean("Switch", false);
	}

}

/**
 * This function is called once each time the robot enters Disabled mode.
 * You can use it to reset any subsystem information you want to clear when
 * the robot is disabled.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic(){
	frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit(){
	/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
	if (autoSelected == "My Auto") {
		autonomousCommand.reset(new MyAutoCommand());
	}
	else {
		autonomousCommand.reset(new ExampleCommand());
	} */

	//autonomousCommand.reset(chooser.GetSelected());
	autonomousCommand = chooser.GetSelected().lock();


	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic(){
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit(){
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic(){
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic(){

}

START_ROBOT_CLASS(Robot)
