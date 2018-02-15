#ifndef TurntoAngle_H
#define TurntoAngle_H

#include "../CommandBase.h"
#include <Timer.h>


class TurntoAngle : public CommandBase {
public:
	TurntoAngle(double, double = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double targetAngle;

	double maxSpeed;
	double minSpeed;

	Timer targetTimer;
	double time;

	void getPreferences();
	void checkKeys();
	double makeContinuous(double);

};

#endif  // TurnToAngle_H
