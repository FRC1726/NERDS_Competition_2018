#ifndef ToggleElevator_H
#define ToggleElevator_H

#include "../CommandBase.h"

class ToggleArm : public CommandBase {
public:
	ToggleArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleElevator_H
