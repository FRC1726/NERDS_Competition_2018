#ifndef ToggleArm_H
#define ToggleArm_H

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

#endif  // ToggleArm_H
