#ifndef OI_H
#define OI_H

#include <Joystick.h>

class OI {
public:
	OI();
	double getAxis(int);
private:
	Joystick driver;
};

#endif  // OI_H
