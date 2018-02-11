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
	int initialPosition;

	void scaleNear(int);
	void scaleFar(int);
	void switchNear(int);
	void switchFar(int);
	void baseline(int);

	void scaleMiddle(char);
	void switchMiddle(char);
	void baselineMiddle(char);
};

#endif  // AutoCommand_H
