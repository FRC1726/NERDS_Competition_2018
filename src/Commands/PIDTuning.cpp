#include "PIDTuning.h"
#include <Preferences.h>
#include "CommandBase.h"

PIDTuning::PIDTuning() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void PIDTuning::Initialize() {
	p = 0;
	getPreferences();
	CommandBase::drivetrain.setPID(0, 0, 0, tolerance);
}

// Called repeatedly when this Command is scheduled to run
void PIDTuning::Execute() {
	p += increment;
	CommandBase::drivetrain.getAngle();


}

// Make this return true when this Command no longer needs to run execute()
bool PIDTuning::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PIDTuning::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDTuning::Interrupted() {

}

bool PIDTuning::findStableOscillation(){
	double angle = CommandBase::drivetrain.getAngle();

	if(angle >= previousAngle){
		potentialPeak = true;
	}else if(potentialPeak){
		peaks.push_back(previousAngle);
		potentialPeak = false;
	}

	double error = PIDTuning::findPeakError();
	if(error >= 0 && error <= tolerance){
		return true;
	}else{
		return false;
	}

}

double PIDTuning::findPeakError(){
	if(peaks.size() <= peaksToCompare){
		return -1;
	}
	double minPeak = *std::min_element(peaks.begin(),peaks.end());
	double maxPeak = *std::max_element(peaks.begin(),peaks.end());
	double peakError = ((maxPeak - minPeak)/maxPeak) * 100;
	return peakError;

}

void PIDTuning::getPreferences() {
	//Speed Values
	tolerance = Preferences::GetInstance()->GetDouble("Auto Turn/Angle Tolerance", 1.0);
	maxSpeed = Preferences::GetInstance()->GetDouble("Auto Turn/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Auto Turn/Min Speed", 0.35);

	//targetTime
	time = Preferences::GetInstance()->GetDouble("Auto Turn/Target Time", 10);

	//Tuning Increments
	increment = Preferences::GetInstance()->GetDouble("PID Tuning/P Increment", 0.01);

	//Peaks Compare
	peaksToCompare = Preferences::GetInstance()->GetInt("PID Tuning/Peaks to Compare", 4);
}

void PIDTuning::checkKeys() {
	//PID Values
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/P")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/P", 0.1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/I")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/D")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/D", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Angle Tolerance")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Angle Tolerance", 1.0);
	}

	//Turn Speeds
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Max Speed", 1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Target Time")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Target Time", 10);
	}

	//Tuning Increments
	if (!Preferences::GetInstance()->ContainsKey("PID Tuning/P Increment")) {
		Preferences::GetInstance()->PutDouble("PID Tuning/P Increment", 0.01);
	}

	//Peak Compare
	if (!Preferences::GetInstance()->ContainsKey("PID Tuning/Peaks to Compare")) {
		Preferences::GetInstance()->PutInt("PID Tuning/Peaks to Compare", 4);
	}
}
