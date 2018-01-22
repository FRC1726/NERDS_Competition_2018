#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveStraight.h"
#include "Commands/ToggleGrabber.h"
#include <WPILib.h>

OI::OI() :
	driver(JOY_DRIVER),
	driver_a(&driver, BUTTON_A),
	driver_b(&driver, BUTTON_B)
{
	// Process operator interface input here.
	driver_a.WhenPressed(new ToggleGrabber);
}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}
