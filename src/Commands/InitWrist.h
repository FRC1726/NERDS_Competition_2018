#ifndef In_ItClaw_H
#define In_ItClaw_H

#include "../CommandBase.h"

class InitWrist : public CommandBase {
public:
	InitWrist();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	void getPreferences();
	double maxSpeed;
};
#endif  // In_ItClaw_H
