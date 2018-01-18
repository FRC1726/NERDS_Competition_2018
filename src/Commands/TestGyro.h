#ifndef TestGyro_H
#define TestGyro_H

#include "../CommandBase.h"

class TestGyro : public CommandBase {
public:
	TestGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TestGyro_H
