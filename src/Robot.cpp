#include "Robot.h"

#include <Commands/Scheduler.h>
#include <Preferences.h>
#include<SmartDashboard/SmartDashboard.h>

#include <DriverStation.h>


#include "CommandBase.h"
#include <string>
#include <iostream>
#include "Commands/InitClaw.h"
#include "CommandGroups/AutoCommand.h"

void Robot::RobotInit(){
	initClaw.reset(new InitClaw);
	initClaw->Start();


	auto camera = CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(640, 480);

	initialPosition.AddDefault("Left", 1);
	initialPosition.AddObject("Middle", 2);
	initialPosition.AddObject("Right", 3);

	SmartDashboard::PutData("Position", &initialPosition);
	if(!Preferences::GetInstance()->ContainsKey("Scale Far")){
		Preferences::GetInstance()->PutBoolean("Scale Far", false);
	}
	if(!Preferences::GetInstance()->ContainsKey("Scale")){
		Preferences::GetInstance()->PutBoolean("Scale", false);
	}
	if(!Preferences::GetInstance()->ContainsKey("Scale Far")){
		Preferences::GetInstance()->PutBoolean("Scale Far", false);
	}

	if(!Preferences::GetInstance()->ContainsKey("Switch")){
		Preferences::GetInstance()->PutBoolean("Switch", false);
	}
	if(!Preferences::GetInstance()->ContainsKey("Switch Far")){
		Preferences::GetInstance()->PutBoolean("Switch Far", false);
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
	autonomousCommand.reset(new AutoCommand(initialPosition.GetSelected()));

	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic(){
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit(){
	//Stops the autonomous command once teleop is enabled. Remove this if you want the commands to continue to run
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
