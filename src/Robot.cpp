#include "Robot.h"

#include <Commands/Scheduler.h>
#include <Preferences.h>
#include<SmartDashboard/SmartDashboard.h>

#include "Commands/InitClaw.h"
#include "CommandGroups/AutoCommand.h"

void Robot::RobotInit(){
	initClaw.reset(new InitClaw);//this resets initclaw so that it's in a known state?
	initClaw->Start();

	auto camera = CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(640, 480);

	initialPosition.AddDefault("Left", 1);
	initialPosition.AddObject("Middle", 2);
	initialPosition.AddObject("Right", 3);

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

void Robot::DisabledInit(){
	CommandBase::winch.setRelease(false);//sets the Winch release to a known state
}
void Robot::DisabledPeriodic(){
	frc::Scheduler::GetInstance()->Run();
}

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
