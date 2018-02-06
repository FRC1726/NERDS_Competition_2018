#ifndef RealWinch_H
#define RealWinch_H

#include "../CommandBase.h"

class ReelWinch : public CommandBase {
public:
	ReelWinch();
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

#endif  // RealWinch_H
