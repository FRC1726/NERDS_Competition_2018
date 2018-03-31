#ifndef TurnToAngle_H
#define TurnToAngle_H

#include "../CommandBase.h"

#include <Timer.h>

class TurnToAngle : public CommandBase {
public:
	TurnToAngle(double, double = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double turnAngle;
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
