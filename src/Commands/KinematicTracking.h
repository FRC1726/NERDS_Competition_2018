#ifndef KinematicTracking_H
#define KinematicTracking_H

#include <NERDS/Polar.h>
#include "../CommandBase.h"
#include <utility>

#include "NERDS/Cartesian.h"

#include <Timer.h>

class KinematicTracking : public CommandBase {
public:
	KinematicTracking(Polar, double);
	KinematicTracking(Cartesian, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Polar currentPosition;
	double currentAngle;
	Timer timer;
	double previousTime;

	Polar calculateVector();
	double calculateAngle();

	double getTime();
};

#endif  // KinematicTracking_H
