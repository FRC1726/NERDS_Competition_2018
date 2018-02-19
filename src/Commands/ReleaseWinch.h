#ifndef ReleaseWinch_H
#define ReleaseWinch_H

#include "../CommandBase.h"

class ReleaseWinch : public CommandBase {
public:
	ReleaseWinch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReleaseWinch_H
