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

private:
	void getPreferences();
	void checkKeys();
	double maxSpeed;
};
#endif  // In_ItClaw_H
