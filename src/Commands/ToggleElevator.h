#ifndef ToggleElevator_H
#define ToggleElevator_H

#include "../CommandBase.h"

class ToggleElevator : public CommandBase {
public:
	ToggleElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleElevator_H
