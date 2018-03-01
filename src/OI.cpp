#include "OI.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>

#include "Commands/ToggleArm.h"
#include "Commands/ToggleClaw.h"
#include "Commands/ReleaseWinch.h"
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
	driver_Y.WhenPressed(new DeleteNetworkTables);
	driver_RB.WhenPressed(new ReleaseWinch);

	driver_SELECT.WhileActive(new DeleteNetworkTables);
	driver_START.WhileActive(new DeleteNetworkTables);

	d_Down.WhileActive(new ReelDown);
	d_Up.WhileActive(new ReelUp);



	//Dem Virtual Buttons! :)
	SmartDashboard::PutData("Delete Network Tables", new DeleteNetworkTables);
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
