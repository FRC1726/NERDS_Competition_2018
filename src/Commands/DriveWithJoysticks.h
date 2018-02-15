#ifndef DriveWithJoysticks_H
#define DriveWithJoysticks_H

#include "../CommandBase.h"

class DriveWithJoysticks : public CommandBase {
public:
	DriveWithJoysticks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double minSpeed;
	double maxSpeed;
	double deadzone;
	double acceleration;
	double currentSpd;
	double driveProfile(double);
	void getPreferences();
	void checkKeys();
};

#endif  // DriveWithJoysticks_H
