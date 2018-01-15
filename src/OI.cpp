#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveStraight.h"

#include <WPILib.h>

OI::OI() :
	driver(JOY_DRIVER),
	driverB(&driver, BUTTON_B)
{
	// Process operator interface input here.
	driverB.WhenPressed(new DriveStraight(.26, 5, 3));
}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}
