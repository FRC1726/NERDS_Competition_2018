#ifndef KinematicTracking_H
#define KinematicTracking_H

#include "../CommandBase.h"
#include <utility.h>


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

	std::pair<double, double> calculateVector();
};

#endif  // KinematicTracking_H
