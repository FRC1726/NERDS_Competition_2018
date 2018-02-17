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

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(306.15));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(10));
	AddSequential(new ToggleElevator());
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());

}

void AutoCommand::scaleFar(int initialPosition){

	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(250));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(192));
	AddSequential(new TurnByAngle(sign * -90));
	AddSequential(new DriveByDistance(69.15));
	AddSequential(new TurnByAngle(sign * -90));
	AddSequential(new ToggleElevator());
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());

}

void AutoCommand::switchNear(int initialPosition){
	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(140.5));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(24));
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::switchFar(int initialPosition){
	int sign = -1;

	if(initialPosition == 1){
		sign = 1;
	}

	AddSequential(new DriveByDistance(84));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(198));
	AddSequential(new TurnByAngle(sign * -90));
	AddSequential(new DriveByDistance(30));
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::baseline(int initialPosition){
	AddSequential(new DriveByDistance(120.5));
}

void AutoCommand::scaleMiddle(char scale){
	int sign;

	if(scale == 'L'){
		sign = 1;
	}else{
		sign = -1;
	}

	AddSequential(new DriveByDistance(19.5));
	AddSequential(new TurnByAngle(sign * -90));
	AddSequential(new DriveByDistance(91.5));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(185.97));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(12));
	AddSequential(new ToggleElevator());
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::switchMiddle(char switchPos){
	int sign;

	if(switchPos == 'L'){
		sign = 1;
	}else{
		sign = -1;
	}

	AddSequential(new DriveByDistance(19.5));
	AddSequential(new TurnByAngle(sign * -90));
	AddSequential(new DriveByDistance(91.5));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(177.75));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new WristDown());
	AddSequential(new ToggleClaw());
}

void AutoCommand::baselineMiddle(char switchPos){
	AddSequential(new DriveByDistance(120.5));
	AddSequential(new TurnByAngle(90));
	AddSequential(new DriveByDistance(120.5));
	AddSequential(new TurnByAngle(-90));
	AddSequential(new DriveByDistance(120.5));
}
