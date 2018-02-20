#ifndef TriggerSpeed_H
#define TriggerSpeed_H

#include "../CommandBase.h"

class TriggerSpeed : public CommandBase {
public:
	TriggerSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double angle;
	double maxSpeed;
	void getPreferences();
	void checkKeys();
};

#endif  // TriggerSpeed_H
