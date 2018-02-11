#ifndef InitClaw_H
#define InitClaw_H

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
	double maxSpeed;

	void getPreferences();
	void checkKeys();
};
#endif  // InitClaw_H
