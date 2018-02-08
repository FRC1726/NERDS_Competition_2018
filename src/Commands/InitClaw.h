#ifndef In_ItClaw_H
#define In_ItClaw_H

#include "../CommandBase.h"

class InitClaw : public CommandBase {
public:
	InitClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // In_ItClaw_H
