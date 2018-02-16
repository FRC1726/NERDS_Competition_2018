#ifndef KinematicTracking_H
#define KinematicTracking_H

#include "../CommandBase.h"
#include <utility.h>

#include <Timer.h>

class KinematicTracking : public CommandBase {
public:
	KinematicTracking(std::pair<double, double>, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::pair<double, double> currentPosition;
	double currentAngle;
	Timer timer;
	double previousTime;

	std::pair<double, double> calculateVector();

	double getTime();
};

#endif  // KinematicTracking_H
