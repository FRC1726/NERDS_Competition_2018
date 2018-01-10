#ifndef ArcadeDriveWithJoysticks_H
#define ArcadeDriveWithJoysticks_H

#include "../CommandBase.h"

class ArcadeDriveWithJoysticks : public CommandBase {
public:
	ArcadeDriveWithJoysticks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArcadeDriveWithJoysticks_H
