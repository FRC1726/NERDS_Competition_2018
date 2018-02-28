#include "OI.h"
#include "RobotMap.h"

#include "Commands/ToggleArm.h"
#include "Commands/ToggleClaw.h"
#include "Commands/ReleaseWinch.h"
#include "Commands/ReelUp.h"
#include "Commands/ReelDown.h"
#include "Commands/DriveOnCurve.h"

OI::OI() :
	driver(JOY_DRIVER),
	driver_A(&driver, BUTTON_A),
	driver_B(&driver, BUTTON_B),
	driver_X(&driver, BUTTON_X),
	driver_Y(&driver, BUTTON_Y),
	driver_LB(&driver, LEFT_BUMP),
	driver_RB(&driver, RIGHT_BUMP),
	pos(120, -90)
{
	// Process operator interface input here.
	driver_A.WhenPressed(new ToggleClaw);
	driver_B.WhenPressed(new ToggleArm);
	driver_X.WhenPressed(new DriveOnCurve(pos));
	driver_RB.WhenPressed(new ReleaseWinch);

	d_Down.WhileActive(new ReelDown);
	d_Up.WhileActive(new ReelUp);
}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}

int OI::getPOV(){
	return driver.GetPOV();
}
