#ifndef DriveOnCurve_H
#define DriveOnCurve_H

#include "../CommandBase.h"\

#include <NERDS/PolarNum.h>

class DriveOnCurve : public CommandBase {
public:
	DriveOnCurve(PolarNum);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double getVelocityRatio();
private:
	PolarNum endPoint;
};

#endif  // DriveOnCurve_H
