#include <Commands/DriveByDistance.h>
#include <Commands/ReelUp.h>
#include <Commands/ToggleArm.h>
#include <Commands/ToggleClaw.h>
#include <Commands/TurnByAngle.h>
#include "OI.h"
#include "RobotMap.h"

#include "Commands/WristUp.h"
#include "Commands/WristMiddle.h"
#include "Commands/WristDown.h"
#include "Commands/ReleaseWinch.h"
#include "Commands/InitClaw.h"
#include "Commands/ReelUp.h"
#include "Commands/ReelDown.h"

OI::OI() :
	driver(JOY_DRIVER),
	driver_a(&driver, BUTTON_A),
	driver_b(&driver, BUTTON_B),
	driver_x(&driver, BUTTON_X),
	driver_y(&driver, BUTTON_Y),
	driver_LB(&driver, LEFT_BUM),
	driver_RB(&driver, RIGHT_BUM)
{
	// Process operator interface input here.
	driver_a.WhenPressed(new ToggleClaw);
	driver_b.WhenPressed(new ToggleArm);
	driver_RB.WhenPressed(new ReleaseWinch);

	d_Down.WhileActive(new ReelDown);
	d_Up.WhileActive(new ReelUp);

	//Virtual Buttons
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
