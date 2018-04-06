#ifndef TriggerSpeed_H
#define TriggerSpeed_H

#include "../CommandBase.h"

class WristWithJoysticks : public CommandBase {
public:
	WristWithJoysticks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double angle;
	double maxSpeed;
	double deadzone;
	void getPreferences();
	double movementProfile(double);
};

#endif  // TriggerSpeed_H
