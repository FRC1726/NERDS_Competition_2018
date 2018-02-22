#ifndef TriggerSpeed_H
#define TriggerSpeed_H

#include "../CommandBase.h"

class RotateWrist : public CommandBase {
public:
	RotateWrist();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double angle;
	double maxSpeed;

	double driveProfile(double);

	void getPreferences();
	void checkKeys();
};

#endif  // TriggerSpeed_H
