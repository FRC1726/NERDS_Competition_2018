#ifndef RealWinch_H
#define RealWinch_H

#include "../CommandBase.h"

class ReelUp : public CommandBase {
public:
	ReelUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double reelSpeed;

	void getPreferences();
	void checkKeys();
};

#endif  // RealWinch_H
