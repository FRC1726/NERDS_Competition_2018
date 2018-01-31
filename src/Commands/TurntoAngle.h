#ifndef TurntoAngle_H
#define TurntoAngle_H

#include "../CommandBase.h"

class TurntoAngle : public CommandBase {
public:
	TurntoAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TurntoAngle_H
