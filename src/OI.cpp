#include <Commands/DriveByDistance.h>
#include <Commands/ReelUp.h>
#include <Commands/ToggleArm.h>
#include <Commands/ToggleClaw.h>
#include <Commands/TurnByAngle.h>
#include "OI.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>

#include "Commands/WristUp.h"
#include "Commands/WristMiddle.h"
#include "Commands/WristDown.h"
#include "Commands/ReleaseWinch.h"
#include "Commands/InitClaw.h"
#include "Commands/ReelUp.h"
#include "Commands/ReelDown.h"
#include "Commands/DeleteNetworkTables.h"


OI::OI() :
	driver(JOY_DRIVER),
	driver_A(&driver, BUTTON_A),
	driver_B(&driver, BUTTON_B),
	driver_X(&driver, BUTTON_X),
	driver_Y(&driver, BUTTON_Y),
	driver_LB(&driver, LEFT_BUMP),
	driver_RB(&driver, RIGHT_BUMP),
	driver_SELECT(&driver, BUTTON_SELECT),
	driver_START(&driver, BUTTON_START)
{
	// Process operator interface input here.
	driver_A.WhenPressed(new ToggleClaw);
	driver_B.WhenPressed(new ToggleArm);
	driver_RB.WhenPressed(new ReleaseWinch);

	d_Down.WhileActive(new ReelDown);
	d_Up.WhileActive(new ReelUp);

	//Dem Virtual Buttons! :)
	SmartDashboard::PutData("Delete Network Tables", new DeleteNetworkTables);

	SmartDashboard::PutData("Commands/Drive Straight", new DriveByDistance(120));
	SmartDashboard::PutData("Commands/Turn By Angle", new TurnByAngle(90));

	SmartDashboard::PutData("Commands/Wrist Up", new WristUp());
	SmartDashboard::PutData("Commands/Wrist Down", new WristDown());
	SmartDashboard::PutData("Commands/Wrist Middle", new WristMiddle());
}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}

int OI::getPOV(){
	return driver.GetPOV();
}

bool OI::getButtonState(int Select){
	switch(Select){
	case BUTTON_A:
		return driver_A.Get();
	case BUTTON_B:
		return driver_B.Get();
	case BUTTON_X:
		return driver_X.Get();
	case BUTTON_Y:
		return driver_Y.Get();
	case LEFT_BUMP:
		return driver_LB.Get();
	case RIGHT_BUMP:
		return driver_RB.Get();
	case BUTTON_SELECT:
		return driver_SELECT.Get();
	case BUTTON_START:
		return driver_START.Get();
	default:
		std::cout << "Something Went Wrong..." << std::endl;
		return false;
	}
}
