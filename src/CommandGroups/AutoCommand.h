#ifndef AutoCommand_H
#define AutoCommand_H

#include <Commands/CommandGroup.h>


class AutoCommand : public CommandGroup {
public:
	AutoCommand(int);
private:
	void getPreferences();
	bool farTarget;
	bool scale;
	bool switchTarget;

	void scaleNear(int);
	void scaleFar(int);
	void switchNear(int);
	void switchFar(int);
	void baseline(int);
};

#endif  // AutoCommand_H
