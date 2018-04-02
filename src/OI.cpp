#include "OI.h"
#include "RobotMap.h"

#include "Commands/ToggleArm.h"
#include "Commands/ToggleClaw.h"
#include "Commands/ReleaseWinch.h"
#include "Commands/ReelUp.h"
#include "Commands/ReelDown.h"

#include "CommandGroups/DriveThroughPath.h"
#include "NERDS/NodeMap.h"
#include "NERDS/Cartesian.h"

OI::OI() :
	driver(JOY_DRIVER),
	driver_A(&driver, BUTTON_A),
	driver_B(&driver, BUTTON_B),
	driver_X(&driver, BUTTON_X),
	driver_Y(&driver, BUTTON_Y),
	driver_LB(&driver, LEFT_BUMP),
	driver_RB(&driver, RIGHT_BUMP)
{
	// Process operator interface input here.
	driver_A.WhenPressed(new ToggleClaw);
	driver_B.WhenPressed(new ToggleArm);
	driver_RB.WhenPressed(new ReleaseWinch);

	d_Down.WhileActive(new ReelDown);
	d_Up.WhileActive(new ReelUp);

	Cartesian source(36,0);
	Cartesian target(72,36);

	NodeMap map;
	path = map.generatePath(source, target);

	SmartDashboard::PutData("Commands/Pathfinding", new DriveThroughPath(path));
}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}

int OI::getPOV(){
	return driver.GetPOV();
}
