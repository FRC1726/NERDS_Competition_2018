#ifndef WristMovement_H
#define WristMovement_H

#include "../CommandBase.h"

class WristMovement : public CommandBase {
public:
	WristMovement();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WristMovement_H
