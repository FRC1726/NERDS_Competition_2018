#ifndef ToggleGrabber_H
#define ToggleGrabber_H

#include "../CommandBase.h"

class ToggleGrabber : public CommandBase {
public:
	ToggleGrabber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Grabber_H

