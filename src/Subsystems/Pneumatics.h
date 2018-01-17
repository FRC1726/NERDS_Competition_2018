#ifndef Pneumatics_H
#define Pneumatics_H

#include <Commands/Subsystem.h>
#include <Solenoid.h>

class Pneumatics : public Subsystem {
public:
	Pneumatics();
	void InitDefaultCommand();
private:
	Solenoid Grabber;
};

#endif  // Pneumatics_H
