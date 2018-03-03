#ifndef WristMiddle_H
#define WristMiddle_H

#include "../CommandBase.h"

class WristMiddle : public CommandBase {
public:
	WristMiddle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double angle;
	void checkKeys();
	void getPreferences();
};

#endif  // WristMiddle_H
