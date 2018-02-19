#ifndef DriveByDistance_H
#define DriveByDistance_H

#include <Timer.h>

#include "../CommandBase.h"

class DriveByDistance : public CommandBase {
public:
	DriveByDistance(double, double = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double maxSpeed;
	double minSpeed;
	double accelDistance;
	double tolerance;

	double leftInitial;
	double rightInitial;
	double averageInitialDistance;
	double targetDistance;

	Timer targetTimer;
	double time;

	double driveProfile(double);
	void getPreferences();
	void checkKeys();
};

#endif  // DriveByDistance_H
