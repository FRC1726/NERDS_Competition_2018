#ifndef DriveStraight_H
#define DriveStraight_H

#include "../CommandBase.h"
#include <Preferences.h>


class DriveStraight : public CommandBase {
public:
	DriveStraight(double, double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double speed;
	double Leftinitial;
	double Rightinitial;
	double target;
	double DriveProfile(double);
};

#endif  // DriveStraight_H
