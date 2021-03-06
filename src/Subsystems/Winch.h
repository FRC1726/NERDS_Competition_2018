#ifndef Winch_H
#define Winch_H

#include <Commands/Subsystem.h>
#include <Solenoid.h>
#include <VictorSP.h>

class Winch : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Winch();
	void InitDefaultCommand();
	void setRelease(bool);
	bool getRelease();
	void Reel(double);
private:
	frc::Solenoid release;
	VictorSP reel;
};

#endif  // Winch_H
