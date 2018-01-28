#ifndef Pneumatics_H
#define Pneumatics_H

#include <Commands/Subsystem.h>
#include <Solenoid.h>

class Pneumatics : public Subsystem {
public:
	Pneumatics();
	void InitDefaultCommand();

	void GrabberOn();
	void GrabberOff();
	bool GetGrabberState();
private:
	Solenoid Grabber;
};

#endif  // Pneumatics_H
