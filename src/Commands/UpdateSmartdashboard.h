#ifndef UpdateSmartdashboard_H
#define UpdateSmartdashboard_H

#include "../CommandBase.h"

class UpdateSmartdashboard : public CommandBase {
public:
	UpdateSmartdashboard();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // UpdateSmartdashboard_H
