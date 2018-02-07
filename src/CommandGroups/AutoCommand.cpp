#include "AutoCommand.h"
#include <Preferences.h>
#include <DriverStation.h>

#include <string>

#include "Commands/DriveByDistance.h"
#include "Commands/WristDown.h"
#include "Commands/WristUp.h"
#include "Commands/TurnByAngle.h"
#include "Commands/ToggleClaw.h"
AutoCommand::AutoCommand(int initialPosition) {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	if (initialPosition == 1 || initialPosition == 3){
			if(switchTarget && !scale){
				if(gameData[0] == 'L'){
					switchNear(initialPosition);
				}else if(gameData[0] == 'R' && farTarget){
					switchFar(initialPosition);
				}else{
					baseline(initialPosition);
				}
			}else if(scale){
				if(gameData[1] == 'L'){
					scaleNear(initialPosition);
				}else if(gameData[1] == 'R' && farTarget){
					scaleFar(initialPosition);
				}else{
					baseline(initialPosition);
				}
			}else{
				baseline(initialPosition);
			}
	}else{

	}

}
void AutoCommand::getPreferences(){
	farTarget = Preferences::GetInstance()->GetBoolean("FarTarget", false);
	scale = Preferences::GetInstance()->GetBoolean("Scale", false);
	switchTarget = Preferences::GetInstance()->GetBoolean("Switch", false);
}

void AutoCommand::scaleNear(int initialPosition){

	int sign = -1;

	if(initialPosition == 1){
		sign = 1
	}


}

void AutoCommand::scaleFar(int initialPosition){
	int sign = -1;

	if(initialPosition == 1){
		sign = 1
	}
}

void AutoCommand::switchNear(int initialPosition){
	int sign = -1;

	if(initialPosition == 1){
		sign = 1
	}

	AddSequential(new DriveByDistance(140.5));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(24));
	//TODO drop cube
}

void AutoCommand::switchFar(int initialPosition){
	int sign = -1;

	if(initialPosition == 1){
		sign = 1
	}

	AddSequential(new DriveByDistance(84));
	AddSequential(new TurnByAngle(sign * 90));
	AddSequential(new DriveByDistance(198));
	AddSequential(new TurnByAngle(sign * -90));
	AddSequential(new DriveByDistance(30));
	//TODO drop cube
}

void AutoCommand::baseline(int initialPosition){

}

