#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>

#include "Triggers/Dpad_Down.h"
#include "Triggers/Dpad_Up.h"

class OI {
public:
	OI();
	double getAxis(int);
	int getPOV();
private:
	Joystick driver;
	JoystickButton driver_a;
	JoystickButton driver_b;
	JoystickButton driver_x;
	JoystickButton driver_y;
	JoystickButton driver_LB;
	JoystickButton driver_RB;

	Dpad_Down d_Down;
	Dpad_Up d_Up;
};

#endif  // OI_H
