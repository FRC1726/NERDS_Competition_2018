#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveStraight.h"
#include "Commands/ToggleGrabber.h"
#include <WPILib.h>
#include "Commands/TestGyro.h"
#include "Commands/AutoTurn.h"

OI::OI() :
	driver(JOY_DRIVER),
	driver_a(&driver, BUTTON_A),
	driver_b(&driver, BUTTON_B),
	driver_x(&driver, BUTTON_X)
{
	// Process operator interface input here.
	driver_a.WhenPressed(new ToggleGrabber);
	driver_b.WhenPressed(new TestGyro);
	driver_x.WhenPressed(new AutoTurn(50,0.35));
}

double OI::getAxis(int axis){
	return driver.GetRawAxis(axis);
}
