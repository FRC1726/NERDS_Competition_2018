#include <Commands/ToggleArm.h>
#include "AutoCommand.h"
#include <Preferences.h>
#include <DriverStation.h>
#include <SmartDashboard/SmartDashboard.h>
#include <string>

#include "Commands/DriveByDistance.h"
#include "Commands/TurnByAngle.h"
#include "Commands/AutoWrist.h"
#include "Commands/Wait.h"
#include "Commands/ToggleClaw.h"

AutoCommand::AutoCommand(int pos) {
	getPreferences();

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
		if(switchTarget){
			if(gameData[0] == near){
				switchNear(initialPosition);
				return;
			}else if(gameData[0] == far && switchTargetFar){
				switchFar(initialPosition);
				return;
			}
		}
		if(scale){
			if(gameData[1] == near){
				scaleNear(initialPosition);
				return;
			}else if(gameData[1] == far && switchTargetFar){
				scaleFar(initialPosition);
				return;
			}
		}
		baseline(initialPosition);
		return;
	}else{

		if(switchTarget){
			switchMiddle(gameData[0]);
		}else if(scale){
			scaleMiddle(gameData[1]);
		}else{
			baselineMiddle(gameData[0]);
		}
	}
}

void AutoCommand::scaleNear(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/scaleNear/Drive By Distance 1/Value", 306.15);
	double D2 = Preferences::GetInstance()->GetDouble("Auto/scaleNear/Drive By Distance 2/Value", 10);
	double T1 = Preferences::GetInstance()->GetDouble("Auto/scaleNear/Turn 1/Value", 90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/scaleNear/Drive By Distance 1/Value", 306.15);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("Auto/scaleNear/Drive By Distance 2/Value", 10);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("Auto/scaleNear/Turn 1/Value", 90);
	double wait = Preferences::GetInstance()->GetDouble("Auto/ScaleNear/Toggle Arm/Wait", 90);
	double autoWrist = Preferences::GetInstance()->GetDouble("Auto/scale/Scale Wrist Angle", 90);

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1, timeout_D1));
	AddSequential(new ToggleArm());
	AddSequential(new nerd::Wait(wait));
	AddSequential(new TurnByAngle(sign * T1, timeout_T1));
	AddSequential(new DriveByDistance(D2, timeout_D2));
	AddSequential(new AutoWrist(autoWrist));
	AddSequential(new ToggleClaw());
}

void AutoCommand::scaleFar(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Drive By Distance 1/Value", 250);
	double D2 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Drive By Distance 2/Value", 192);
	double D3 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Drive By Distance 3/Value", 69.15);
	double T1 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Turn 1/Value", 90);
	double T2 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Turn 2/Value", -90);
	double T3 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Turn 3/Value", -90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Drive By Distance 1/Timeout", 250);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Drive By Distance 2/Timeout", 192);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Drive By Distance 3/Timeout", 69.15);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Turn 1/Timeout", 90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Turn 2/Timeout", -90);
	double timeout_T3 = Preferences::GetInstance()->GetDouble("Auto/scaleFar/Turn 3/Timeout", -90);
	double wait = Preferences::GetInstance()->GetDouble("Auto/ScaleFar/Toggle Arm/Wait", 90);
	double autoWrist = Preferences::GetInstance()->GetDouble("Auto/scale/Scale Wrist Angle", 90);

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1, timeout_D1));
	AddSequential(new TurnByAngle(sign * T1, timeout_T1));
	AddSequential(new DriveByDistance(D2, timeout_D2));
	AddSequential(new ToggleArm());
	AddSequential(new nerd::Wait(wait));
	AddSequential(new TurnByAngle(sign * T2, timeout_T2));
	AddSequential(new DriveByDistance(D3, timeout_D3));
	AddSequential(new TurnByAngle(sign * T3, timeout_T3));
	AddSequential(new AutoWrist(autoWrist));
	AddSequential(new ToggleClaw());
}

void AutoCommand::switchNear(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/switchNear/Drive By Distance 1/Value", 140.5);
	double D2 = Preferences::GetInstance()->GetDouble("Auto/switchNear/Drive By Distance 2/Value", 12);
	double T1 = Preferences::GetInstance()->GetDouble("Auto/switchNear/Turn 1/Value", 90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/switchNear/Drive By Distance 1/Timeout", 140.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("Auto/switchNear/Drive By Distance 2/Timeout", 12);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("Auto/switchNear/Turn 1/Timeout", 90);
	double autoWrist = Preferences::GetInstance()->GetDouble("Auto/switch/Switch Wrist Angle", 90);

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1, timeout_D1));
	AddSequential(new TurnByAngle(sign * T1, timeout_T1));
	AddSequential(new DriveByDistance(D2, timeout_D2));
	AddSequential(new AutoWrist(autoWrist));
	AddSequential(new ToggleClaw());
}

void AutoCommand::switchFar(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Drive By Distance 1/Value", 84);
	double D2 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Drive By Distance 2/Value", 148);
	double D3 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Drive By Distance 3/Value", 30);
	double T1 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Turn 1/Value", 90);
	double T2 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Turn 2/Value", -90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Drive By Distance 1/Timeout", 84);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Drive By Distance 2/Timeout", 148);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Drive By Distance 3/Timeout", 30);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Turn 1/Timeout", 90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("Auto/switchFar/Turn 2/Timeout", -90);
	double autoWrist = Preferences::GetInstance()->GetDouble("Auto/switch/Switch Wrist Angle", 90);

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(D1, timeout_D1));
	AddSequential(new TurnByAngle(sign * T1, timeout_T1));
	AddSequential(new DriveByDistance(D2, timeout_D2));
	AddSequential(new TurnByAngle(sign * T2, timeout_T2));
	AddSequential(new DriveByDistance(D3, timeout_D3));
	AddSequential(new AutoWrist(autoWrist));
	AddSequential(new ToggleClaw());
}

void AutoCommand::baseline(int initialPosition){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/baseline/Drive By Distance 1/Value", 120.5);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/baseline/Drive By Distance 1/Timeout", 120.5);

	AddSequential(new DriveByDistance(D1, timeout_D1));
}

void AutoCommand::scaleMiddle(char scale){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 1/Value", 19.5);
	double D2 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 2/Value", 91.5);
	double D3 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 3/Value", 186);
	double D4 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 4/Value", 12);
	double T1 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Turn 1/Value", -90);
	double T2 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Turn 2/Value", 90);
	double T3 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Turn 3/Value", 90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 1/Timeout", 19.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 2/Timeout", 91.5);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 3/Timeout", 186);
	double timeout_D4 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Drive By Distance 4/Timeout", 12);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Turn 1/Timeout", -90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Turn 2/Timeout", 90);
	double timeout_T3 = Preferences::GetInstance()->GetDouble("Auto/scaleMiddle/Turn 3/Timeout", 90);
	double wait = Preferences::GetInstance()->GetDouble("Auto/ScaleMiddle/Toggle Arm/Wait", 90);
	double autoWrist = Preferences::GetInstance()->GetDouble("Auto/scale/Scale Wrist Angle", 90);
	double rightOffset = Preferences::GetInstance()->GetDouble("Auto/Right Offset", 0);

	int sign = -1;

	if(scale == 'L'){
		sign = 1;
		rightOffset = -rightOffset;
	}

	AddSequential(new DriveByDistance(D1, timeout_D1));
	AddSequential(new TurnByAngle(sign * T1, timeout_T1));
	AddSequential(new DriveByDistance(D2 - rightOffset, timeout_D2));
	AddSequential(new TurnByAngle(sign * T2, timeout_T2));
	AddSequential(new ToggleArm());
	AddSequential(new nerd::Wait(wait));
	AddSequential(new DriveByDistance(D3, timeout_D3));
	AddSequential(new TurnByAngle(sign * T3, timeout_T3));
	AddSequential(new DriveByDistance(D4, timeout_D4));
	AddSequential(new AutoWrist(autoWrist));
	AddSequential(new ToggleClaw());
}

void AutoCommand::switchMiddle(char switchPos){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Drive By Distance 1/Value", 19.5);
	double D2 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Drive By Distance 2/Value", 91.5);
	double D3 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Drive By Distance 3/Value", 19.5);
	double T1 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Turn 1/Value", -90);
	double T2 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Turn 2/Value", 90);
	double T3 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Turn 3/Value", 90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Drive By Distance 1/Timeout", 19.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Drive By Distance 2/Timeout", 91.5);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Drive By Distance 3/Timeout", 19.5);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Turn 1/Timeout", -90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Turn 2/Timeout", 90);
	double timeout_T3 = Preferences::GetInstance()->GetDouble("Auto/switchMiddle/Turn 3/Timeout", 90);
	double autoWrist = Preferences::GetInstance()->GetDouble("Auto/switch/Switch Wrist Angle", 90);
	double rightOffset = Preferences::GetInstance()->GetDouble("Auto/Right Offset", 0);

	int sign = -1;

	if(switchPos == 'L'){
		sign = 1;
		rightOffset = -rightOffset;
	}

	AddSequential(new DriveByDistance(D1, timeout_D1));
	AddSequential(new TurnByAngle(sign * T1, timeout_T1));
	AddSequential(new DriveByDistance(D2 - rightOffset, timeout_D2));
	AddSequential(new TurnByAngle(sign * T2, timeout_T2));
	AddSequential(new DriveByDistance(D3, timeout_D3));
	AddSequential(new TurnByAngle(sign * T3, timeout_T3));
	AddSequential(new AutoWrist(autoWrist));
	AddSequential(new ToggleClaw());
}

void AutoCommand::baselineMiddle(char switchPos){
	double D1 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Drive By Distance 1/Value", 19.5);
	double D2 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Drive By Distance 2/Value", 91.5);
	double D3 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Drive By Distance 3/Value", 19.5);
	double T1 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Turn 1/Value", 90);
	double T2 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Turn 2/Value", -90);
	double timeout_D1 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Drive By Distance 1/Timeout", 19.5);
	double timeout_D2 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Drive By Distance 2/Timeout", 91.5);
	double timeout_D3 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Drive By Distance 3/Timeout", 19.5);
	double timeout_T1 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Turn 1/Timeout", 90);
	double timeout_T2 = Preferences::GetInstance()->GetDouble("Auto/baselineMiddle/Turn 2/Timeout", -90);
	double rightOffset = Preferences::GetInstance()->GetDouble("Auto/Right Offset", 0);

	AddSequential(new DriveByDistance(D1, timeout_D1));
	AddSequential(new TurnByAngle(T1, timeout_T1));
	AddSequential(new DriveByDistance(D2 - rightOffset, timeout_D2));
	AddSequential(new TurnByAngle(T2, timeout_T2));
	AddSequential(new DriveByDistance(D3, timeout_D3));
}

void AutoCommand::getPreferences(){
	scaleTargetFar = Preferences::GetInstance()->GetBoolean("Far Scale", false);
	scale = Preferences::GetInstance()->GetBoolean("Scale", false);
	switchTarget = Preferences::GetInstance()->GetBoolean("Switch", false);
	switchTargetFar = Preferences::GetInstance()->GetBoolean("Far Switch", false);
}
