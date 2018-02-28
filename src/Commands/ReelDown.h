#ifndef ReelDown_H
#define ReelDown_H

#include "../CommandBase.h"

class ReelDown : public CommandBase {
public:
	ReelDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	void getPreferences();
	void checkKeys();
	double reelSpeed;
};

#endif  // ReelDown_H
