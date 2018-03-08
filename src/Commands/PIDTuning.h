#pragma once

#include <Commands/Command.h>

#include <vector>

class PIDTuning : public frc::Command {
public:
	PIDTuning();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	void checkKeys();
	void getPreferences();
	void findStableOscillation();
	double findPeakError();

	double time;
	double minSpeed;
	double maxSpeed;
	double tolerance;

	double p;
	double increment;

	double previousAngle;
	bool potentialPeak;

	vector<double> peaks;

	int peaksToCompare;
};

