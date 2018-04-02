#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include <vector>
#include <NERDS/Polar.h>

#include "Triggers/Dpad_Down.h"
#include "Triggers/Dpad_Up.h"

class OI {
public:
	OI();
	double getAxis(int);
	int getPOV();
	bool getButtonState(int);
private:
	Joystick driver;
	JoystickButton driver_A;
	JoystickButton driver_B;
	JoystickButton driver_X;
	JoystickButton driver_Y;
	JoystickButton driver_LB;
	JoystickButton driver_RB;
	JoystickButton driver_SELECT;
	JoystickButton driver_START;

	Dpad_Down d_Down;
	Dpad_Up d_Up;

	std::vector<Polar> path;
};

#endif  // OI_H
