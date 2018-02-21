#include "AutoCommand.h"
#include <Preferences.h>
#include <DriverStation.h>

#include <string>

#include "Commands/DriveByDistance.h"
#include "Commands/WristDown.h"
#include "Commands/WristUp.h"
#include "Commands/TurnByAngle.h"
#include "Commands/ToggleClaw.h"
#include "Commands/ToggleElevator.h"

AutoCommand::AutoCommand(int pos) {
	checkKeys();

	initialPosition = pos;
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	char far, near;
	if(initialPosition == 1){
		far = 'R';
		near = 'L';
	}else{
		far = 'L';
		near = 'R';
	}

	if (initialPosition == 1 || initialPosition == 3){
			if(switchTarget && !scale){
				if(gameData[0] == near){
					switchNear(initialPosition);
				}else if(gameData[0] == far && farTarget){
					switchFar(initialPosition);
				}else{
					baseline(initialPosition);
				}
			}else if(scale){
				if(gameData[1] == near){
					scaleNear(initialPosition);
				}else if(gameData[1] == far && farTarget){
					scaleFar(initialPosition);
				}else{
					baseline(initialPosition);
				}
			}else{
				baseline(initialPosition);
			}
	}else{
		if(scale){
			scaleMiddle(gameData[1]);
		}else if(switchTarget){
			switchMiddle(gameData[0]);
		}else{
			baselineMiddle(gameData[0]);
		}
	}
}

void AutoCommand::getPreferences(){
	farTarget = Preferences::GetInstance()->GetBoolean("FarTarget", false);
	scale = Preferences::GetInstance()->GetBoolean("Scale", false);
	switchTarget = Preferences::GetInstance()->GetBoolean("Switch", false);
//	initialPosition = dynamic_cast<frc::SendableChooser<int>* >(SmartDashboard::GetData("Position"))->GetSelected();
}

void AutoCommand::scaleNear(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("scaleNear/Drive By Distance 1/Value", 306.15);
	double D2 = Preferences::GetInstance()->GetDouble("scaleNear/Drive By Distance 2/Value", 10);
	double T1 = Preferences::GetInstance()->GetDouble("scaleNear/Turn 1/Value", 90);

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1));
	AddSequential(new TurnByAngle(sign * T1));
	AddSequential(new DriveByDistance(D2));
	AddSequential(new ToggleElevator());
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());

}

void AutoCommand::scaleFar(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("scaleFar/Drive By Distance 1/Value", 250);
	double D2 = Preferences::GetInstance()->GetDouble("scaleFar/Drive By Distance 2/Value", 192);
	double D3 = Preferences::GetInstance()->GetDouble("scaleFar/Drive By Distance 3/Value", 69.15);
	double T1 = Preferences::GetInstance()->GetDouble("scaleFar/Turn 1/Value", 90);
	double T2 = Preferences::GetInstance()->GetDouble("scaleFar/Turn 2/Value", -90);
	double T3 = Preferences::GetInstance()->GetDouble("scaleFar/Turn 3/Value", -90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("scaleFar/Drive By Distance 1/Timeout", 250);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("scaleFar/Drive By Distance 2/Timeout", 192);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("scaleFar/Drive By Distance 3/Timeout", 69.15);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("scaleFar/Turn 1/Timeout", 90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("scaleFar/Turn 2/Timeout", -90);
	double timeout_T3 = Preferences::GetInstance()->GetDouble("scaleFar/Turn 3/Timeout", -90);


	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1));
	AddSequential(new TurnByAngle(sign * T1));
	AddSequential(new DriveByDistance(D2));
	AddSequential(new TurnByAngle(sign * T2));
	AddSequential(new DriveByDistance(D3));
	AddSequential(new TurnByAngle(sign * T3));
	AddSequential(new ToggleElevator());
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());

}

void AutoCommand::switchNear(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("switchNear/Drive By Distance 1/Value", 140.5);
	double D2 = Preferences::GetInstance()->GetDouble("switchNear/Drive By Distance 2/Value", 12);
	double T1 = Preferences::GetInstance()->GetDouble("switchNear/Turn 1/Value", 90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("switchNear/Drive By Distance 1/Timeout", 140.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("switchNear/Drive By Distance 2/Timeout", 12);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("switchNear/Turn 1/Timeout", 90);

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1));
	AddSequential(new TurnByAngle(sign * T1));
	AddSequential(new DriveByDistance(D2));
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::switchFar(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("switchFar/Drive By Distance 1/Value", 84);
	double D2 = Preferences::GetInstance()->GetDouble("switchFar/Drive By Distance 2/Value", 148);
	double D3 = Preferences::GetInstance()->GetDouble("switchFar/Drive By Distance 3/Value", 30);
	double T1 = Preferences::GetInstance()->GetDouble("switchFar/Turn 1/Value", 90);
	double T2 = Preferences::GetInstance()->GetDouble("switchFar/Turn 2/Value", -90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("switchFar/Drive By Distance 1/Timeout", 84);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("switchFar/Drive By Distance 2/Timeout", 148);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("switchFar/Drive By Distance 3/Timeout", 30);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("switchFar/Turn 1/Timeout", 90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("switchFar/Turn 2/Timeout", -90);

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1));
	AddSequential(new TurnByAngle(sign * T1));
	AddSequential(new DriveByDistance(D2));
	AddSequential(new TurnByAngle(sign * T2));
	AddSequential(new DriveByDistance(D3));
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::baseline(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("baseline/Drive By Distance 1/Value", 120.5);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("baseline/Drive By Distance 1/Timeout", 120.5);

	AddSequential(new DriveByDistance(D1));
}

void AutoCommand::scaleMiddle(char scale){
	double D1 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 1/Value", 19.5);
	double D2 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 2/Value", 91.5);
	double D3 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 3/Value", 186);
	double D4 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 4/Value", 12);
	double T1 = Preferences::GetInstance()->GetDouble("scaleMiddle/Turn 1/Value", -90);
	double T2 = Preferences::GetInstance()->GetDouble("scaleMiddle/Turn 2/Value", 90);
	double T3 = Preferences::GetInstance()->GetDouble("scaleMiddle/Turn 3/Value", 90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 1/Timeout", 19.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 2/Timeout", 91.5);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 3/Timeout", 186);
	double timeout_D4 = Preferences::GetInstance()->GetDouble("scaleMiddle/Drive By Distance 4/Timeout", 12);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("scaleMiddle/Turn 1/Timeout", -90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("scaleMiddle/Turn 2/Timeout", 90);
	double timeout_T3 = Preferences::GetInstance()->GetDouble("scaleMiddle/Turn 3/Timeout", 90);

	int sign;

	if(scale == 'L'){
		sign = 1;
	}else{
		sign = -1;
	}

	AddSequential(new DriveByDistance(D1));
	AddSequential(new TurnByAngle(sign * T1));
	AddSequential(new DriveByDistance(D2));
	AddSequential(new TurnByAngle(sign * T2));
	AddSequential(new DriveByDistance(D3));
	AddSequential(new TurnByAngle(sign * T3));
	AddSequential(new DriveByDistance(D4));
	AddSequential(new ToggleElevator());
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::switchMiddle(char switchPos){
	double D1 = Preferences::GetInstance()->GetDouble("switchMiddle/Drive By Distance 1/Value", 19.5);
	double D2 = Preferences::GetInstance()->GetDouble("switchMiddle/Drive By Distance 2/Value", 91.5);
	double D3 = Preferences::GetInstance()->GetDouble("switchMiddle/Drive By Distance 3/Value", 19.5);
	double T1 = Preferences::GetInstance()->GetDouble("switchMiddle/Turn 1/Value", -90);
	double T2 = Preferences::GetInstance()->GetDouble("switchMiddle/Turn 2/Value", 90);
	double T3 = Preferences::GetInstance()->GetDouble("switchMiddle/Turn 3/Value", 90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("switchMiddle/Drive By Distance 1/Timeout", 19.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("switchMiddle/Drive By Distance 2/Timeout", 91.5);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("switchMiddle/Drive By Distance 3/Timeout", 19.5);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("switchMiddle/Turn 1/Timeout", -90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("switchMiddle/Turn 2/Timeout", 90);
	double timeout_T3 = Preferences::GetInstance()->GetDouble("switchMiddle/Turn 3/Timeout", 90);

	int sign;

	if(switchPos == 'L'){
		sign = 1;
	}else{
		sign = -1;
	}

	AddSequential(new DriveByDistance(D1));
	AddSequential(new TurnByAngle(sign * T1));
	AddSequential(new DriveByDistance(D2));
	AddSequential(new TurnByAngle(sign * T2));
	AddSequential(new DriveByDistance(D3));
	AddSequential(new TurnByAngle(sign * T3));
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::baselineMiddle(char switchPos){
	double D1 = Preferences::GetInstance()->GetDouble("baselineMiddle/Drive By Distance 1/Value", 19.5);
	double D2 = Preferences::GetInstance()->GetDouble("baselineMiddle/Drive By Distance 2/Value", 91.5);
	double D3 = Preferences::GetInstance()->GetDouble("baselineMiddle/Drive By Distance 3/Value", 19.5);
	double T1 = Preferences::GetInstance()->GetDouble("baselineMiddle/Turn 1/Value", 90);
	double T2 = Preferences::GetInstance()->GetDouble("baselineMiddle/Turn 2/Value", -90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("baselineMiddle/Drive By Distance 1/Timeout", 19.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("baselineMiddle/Drive By Distance 2/Timeout", 91.5);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("baselineMiddle/Drive By Distance 3/Timeout", 19.5);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("baselineMiddle/Turn 1/Timeout", 90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("baselineMiddle/Turn 2/Timeout", -90);

	AddSequential(new DriveByDistance(D1));
	AddSequential(new TurnByAngle(T1));
	AddSequential(new DriveByDistance(D2));
	AddSequential(new TurnByAngle(T2));
	AddSequential(new DriveByDistance(D3));
}
void AutoCommand::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("scaleNear/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("scaleNear/Drive By Distance 1/Value", 306.15);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleNear/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("scaleNear/Drive By Distance 2/Value", 10);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleNear/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("scaleNear/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Drive By Distance 1/Value", 250);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Drive By Distance 2/Value", 192);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Drive By Distance 3/Value", 69.15);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Turn 2/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Turn 3/Value")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Turn 3/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchNear/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("switchNear/Drive By Distance 1/Value", 140.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchNear/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("switchNear/Drive By Distance 2/Value", 12);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchNear/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("switchNear/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("switchFar/Drive By Distance 1/Value", 84);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("switchFar/Drive By Distance 2/Value", 148);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("switchFar/Drive By Distance 3/Value", 30);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("switchFar/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("switchFar/Turn 2/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("baseline/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("baseline/Drive By Distance 1/Value", 120.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 1/Value", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 2/Value", 91.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 3/Value", 186);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 4/Value")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 4/Value", 12);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Turn 1/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Turn 2/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Turn 3/Value")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Turn 3/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Drive By Distance 1/Value", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Drive By Distance 2/Value", 91.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Drive By Distance 3/Value", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Turn 1/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Turn 2/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Turn 3/Value")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Turn 3/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Drive By Distance 1", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Drive By Distance 2/Value", 91.50);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Drive By Distance 3/Value", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Turn 2/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleNear/Drive By Distance 1/Timeout")) {
			Preferences::GetInstance()->PutDouble("scaleNear/Drive By Distance 1/Timeout", 306.15);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleNear/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleNear/Drive By Distance 2/Timeout", 10);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleNear/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleNear/Turn 1/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Drive By Distance 1/Timeout", 250);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Drive By Distance 2/Timeout", 192);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Drive By Distance 3", 69.15);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Turn 1/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Turn 2/Timeout", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleFar/Turn 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleFar/Turn 3/Timeout", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchNear/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchNear/Drive By Distance 1/Timeout", 140.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchNear/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchNear/Drive By Distance 2/Timeout", 12);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchNear/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchNear/Turn 1/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchFar/Drive By Distance 1/Timeout", 84);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchFar/Drive By Distance 2/Timeout", 148);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchFar/Drive By Distance 3/Timeout", 30);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchFar/Turn 1/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchFar/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchFar/Turn 2/Timeout", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("baseline/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("baseline/Drive By Distance 1/Timeout", 120.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 1/Timeout", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 2/Timeout", 91.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 3/Timeout", 186);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Drive By Distance 4/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Drive By Distance 4/Timeout", 12);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Turn 1/Timeout", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Turn 2/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("scaleMiddle/Turn 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("scaleMiddle/Turn 3/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Drive By Distance 1/Timeout", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Drive By Distance 2/Timeout", 91.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Drive By Distance 3/Timeout", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Turn 1/Timeout", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Turn 2/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("switchMiddle/Turn 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("switchMiddle/Turn 3/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Drive By Distance 1/Timeout", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Drive By Distance 2/Timeout", 91.50);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Drive By Distance 3/Timeout", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Turn 1/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("baselineMiddle/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("baselineMiddle/Turn 2/Timeout", -90);
	}
}
