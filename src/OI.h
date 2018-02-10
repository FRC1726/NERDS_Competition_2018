#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>

class OI {
public:
	OI();
	double getAxis(int);
private:
	Joystick driver;
	JoystickButton driver_a;
	JoystickButton driver_b;
	JoystickButton driver_x;
	JoystickButton driver_y;
	JoystickButton driver_LB;
	JoystickButton driver_RB;
};

#endif  // OI_H
