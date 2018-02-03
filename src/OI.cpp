#include <Commands/DriveByDistance.h>
#include <Commands/TurnByAngle.h>
#include "OI.h"
#include "RobotMap.h"

#include "Commands/ToggleGrabber.h"
#include "Commands/WristUp.h"
#include "Commands/WristDown.h"

OI::OI() :
	driver(JOY_DRIVER),
	driver_a(&driver, BUTTON_A),
	driver_b(&driver, BUTTON_B),
	driver_x(&driver, BUTTON_X),
	driver_y(&driver, BUTTON_Y)
{
	// Process operator interface input here.
	driver_a.WhenPressed(new ToggleGrabber);
	driver_x.WhenPressed(new WristUp);
	driver_y.WhenPressed(new WristDown);
}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}

