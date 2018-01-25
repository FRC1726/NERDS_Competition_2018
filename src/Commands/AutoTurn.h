#ifndef AutoTurn_H
#define AutoTurn_H

#include "../CommandBase.h"

class AutoTurn : public CommandBase {
public:
	AutoTurn(double,double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double turnAngle;
	double targetAngle;
	double maxSpeed;
};

#endif  // AutoTurn_H
