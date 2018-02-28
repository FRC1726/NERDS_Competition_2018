#ifndef KinematicTracking_H
#define KinematicTracking_H

#include "../CommandBase.h"
#include <utility>

#include "NERDS/PolarNum.h"
#include "NERDS/Cartesian.h"

#include <Timer.h>

class KinematicTracking : public CommandBase {
public:
	KinematicTracking(PolarNum, double);
	KinematicTracking(Cartesian, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	PolarNum currentPosition;
	double currentAngle;
	Timer timer;
	double previousTime;

	PolarNum calculateVector();
	double calculateAngle();

	double getTime();
};

#endif  // KinematicTracking_H
