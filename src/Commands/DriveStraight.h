#ifndef DriveStraight_H
#define DriveStraight_H

#include "../CommandBase.h"

class DriveStraight : public CommandBase {
public:
	DriveStraight(double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double speed;
	double target;
	double position;
};

#endif  // DriveStraight_H
