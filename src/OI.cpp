#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveStraight.h"

#include <WPILib.h>

OI::OI() :
	driver(JOY_DRIVER)
{
	// Process operator interface input here.

}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}
