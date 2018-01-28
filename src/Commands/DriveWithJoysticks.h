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
	double driveProfile(double);
};

#endif  // DriveWithJoysticks_H
