#ifndef WristDown_H
#define WristDown_H

#include "../CommandBase.h"

class WristDown : public CommandBase {
public:
	WristDown();
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

#endif  // WristDown_H
