#ifndef TurnByAngle_H
#define TurnByAngle_H

#include "../CommandBase.h"
#include <Timer.h>



class TurnByAngle : public CommandBase {
public:
	TurnByAngle(double, double = 0);
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
	double makeContinuous(double);

};

#endif  // TurnByAngle_H
