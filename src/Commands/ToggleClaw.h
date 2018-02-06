#ifndef ToggleGrabber_H
#define ToggleGrabber_H

#include "../CommandBase.h"

class ToggleClaw : public CommandBase {
public:
	ToggleClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Grabber_H

