#ifndef ReleaseAndReal_H
#define ReleaseAndReal_H

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

#endif  // ReleaseAndReal_H
