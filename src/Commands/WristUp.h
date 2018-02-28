#ifndef WristUp_H
#define WristUp_H

#include "../CommandBase.h"

class WristUp : public CommandBase {
public:
	WristUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double angle;

	void getPreferences();
	void checkKeys();
};

#endif  // WristUp_H
