#ifndef AutoWrist_H
#define AutoWrist_H

#include "../CommandBase.h"

class AutoWrist : public CommandBase {
public:
	AutoWrist(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double angle;
	void checkKeys();
	void getPreferences();
};

#endif  // AutoWrist_H
