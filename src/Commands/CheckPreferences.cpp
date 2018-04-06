/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CheckPreferences.h"

#include <Preferences.h>

CheckPreferences::CheckPreferences() {
	//Wrist
	if (!Preferences::GetInstance()->ContainsKey("Wrist/P")) {
		Preferences::GetInstance()->PutDouble("Wrist/P", 1.75);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/I")) {
		Preferences::GetInstance()->PutDouble("Wrist/I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/D")) {
		Preferences::GetInstance()->PutDouble("Wrist/D", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/F")) {
		Preferences::GetInstance()->PutDouble("Wrist/F", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Wrist/Max Speed", 1.25);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Angle Range")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Angle Range", 5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Down Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Down Angle", 198);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Middle Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Middle Angle", 120);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Up Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Up Angle", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Deadzone")) {
			Preferences::GetInstance()->PutDouble("Wrist/Deadszone", 0.025);
	}

	//Auto Drive
	//PID Values
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/P")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/P", 0.0475);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/I")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/I", 0.009);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/D")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/D", 0.099);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Distance Tolerance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Distance Tolerance", 2.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Angle Tolerance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Angle Tolerance", 3.0);
	}

	//Drive Profile Values
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Max Speed", 0.8);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Accel Distance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Accel Distance", 24.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Decel Distance")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Decel Distance", 24.0);
	}

	//Timer
	if (!Preferences::GetInstance()->ContainsKey("Auto Drive/Target Timer")) {
		Preferences::GetInstance()->PutDouble("Auto Drive/Target Timer", 0.2);
	}

	//Joystick
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Max Speed", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Deadzone")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Deadzone", .025);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/acceleration")) {
		Preferences::GetInstance()->PutDouble("Joysticks/acceleration", 0);
	}

	//Reel
	if (!Preferences::GetInstance()->ContainsKey("Reel/Speed")) {
		Preferences::GetInstance()->PutDouble("Reel/Speed", 1);
	}

	//Auto Turn
	//PID Values
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/P")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/P", .0475);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/I")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/I", 0.009);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/D")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/D", 0.099);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Angle Tolerance")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Angle Tolerance", 3.0);
	}

	//Turn Speeds
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Max Speed", 0.64);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto Turn/Target Time")) {
		Preferences::GetInstance()->PutDouble("Auto Turn/Target Time", 0.5);
	}

	//Auto Modes
	//Scale Near Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleNear/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleNear/Drive By Distance 1/Value", 306.15);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleNear/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleNear/Drive By Distance 2/Value", 10);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleNear/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleNear/Turn 1/Value", 90);
	}
	//Scale Near Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleNear/Drive By Distance 1/Timeout")) {
			Preferences::GetInstance()->PutDouble("Auto/scaleNear/Drive By Distance 1/Timeout", 5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleNear/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleNear/Drive By Distance 2/Timeout", 1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleNear/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleNear/Turn 1/Timeout", 1.75);
	}

	// Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Drive By Distance 1/Value", 250);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Drive By Distance 2/Value", 192);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Drive By Distance 3/Value", 69.15);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Turn 2/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Turn 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Turn 3/Value", -90);
	}
	//Scale Far Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Drive By Distance 1/Timeout", 4);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Drive By Distance 2/Timeout", 4);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Drive By Distance 3", 3);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Turn 1/Timeout", 1.75);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Turn 2/Timeout", 1.75);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleFar/Turn 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleFar/Turn 3/Timeout", 1.75);
	}

	//Switch Near Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchNear/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchNear/Drive By Distance 1/Value", 140.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchNear/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchNear/Drive By Distance 2/Value", 12);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchNear/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchNear/Turn 1/Value", 90);
	}
	//Switch Near Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchNear/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchNear/Drive By Distance 1/Timeout", 4);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchNear/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchNear/Drive By Distance 2/Timeout", 1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchNear/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchNear/Turn 1/Timeout", 1.75);
	}

	//Switch Far Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Drive By Distance 1/Value", 84);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Drive By Distance 2/Value", 148);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Drive By Distance 3/Value", 30);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Turn 2/Value", -90);
	}
	//Switch Far Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Drive By Distance 1/Timeout", 3);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Drive By Distance 2/Timeout", 4);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Drive By Distance 3/Timeout", 2);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Turn 1/Timeout", 1.75);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchFar/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchFar/Turn 2/Timeout", 1.75);
	}

	//Baseline Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/baseline/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/baseline/Drive By Distance 1/Value", 120.5);
	}
	//Baseline Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/baseline/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/baseline/Drive By Distance 1/Timeout", 4);
	}

	//Scale Middle Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 1/Value", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 2/Value", 91.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 3/Value", 186);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 4/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 4/Value", 12);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Turn 1/Value", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Turn 2/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Turn 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Turn 3/Value", 90);
	}
	//Scale Middle Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 1/Timeout", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 2/Timeout", 91.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 3/Timeout", 186);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Drive By Distance 4/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Drive By Distance 4/Timeout", 12);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Turn 1/Timeout", -90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Turn 2/Timeout", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/scaleMiddle/Turn 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/scaleMiddle/Turn 3/Timeout", 90);
	}

	//Switch Middle Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Drive By Distance 1/Value", 30);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Drive By Distance 2/Value", 80);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Drive By Distance 3/Value", 30);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Turn 1/Value", -45);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Turn 2/Value", 45);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Turn 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Turn 3/Value", 0);
	}
	//Switch Middle Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Drive By Distance 1/Timeout", 2);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Drive By Distance 2/Timeout", 3);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Drive By Distance 3/Timeout", 2);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Turn 1/Timeout", 1.75);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Turn 2/Timeout", 1.75);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/switchMiddle/Turn 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/switchMiddle/Turn 3/Timeout", 1.75);
	}

	//Baseline Middle Values
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Drive By Distance 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Drive By Distance 1/Value", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Drive By Distance 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Drive By Distance 2/Value", 91.50);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Drive By Distance 3/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Drive By Distance 3/Value", 19.5);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Turn 1/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Turn 1/Value", 90);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Turn 2/Value")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Turn 2/Value", -90);
	}
	//Baseline Middle Timeouts
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Drive By Distance 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Drive By Distance 1/Timeout", 2);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Drive By Distance 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Drive By Distance 2/Timeout", 4);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Drive By Distance 3/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Drive By Distance 3/Timeout", 2);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Turn 1/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Turn 1/Timeout", 1.75);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/baselineMiddle/Turn 2/Timeout")) {
		Preferences::GetInstance()->PutDouble("Auto/baselineMiddle/Turn 2/Timeout", 1.75);
	}
	//Toggle Arm Wait
	if (!Preferences::GetInstance()->ContainsKey("Auto/ScaleNear/Toggle Arm/Wait")) {
		Preferences::GetInstance()->PutDouble("Auto/ScaleNear/Toggle Arm/Wait", 1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/ScaleFar/Toggle Arm/Wait")) {
		Preferences::GetInstance()->PutDouble("Auto/ScaleFar/Toggle Arm/Wait", 1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Auto/ScaleMiddle/Toggle Arm/Wait")) {
		Preferences::GetInstance()->PutDouble("Auto/ScaleMiddle/Toggle Arm/Wait", 1);
	}
	//Scale Wrist Angle
	if (!Preferences::GetInstance()->ContainsKey("Auto/scale/Scale Wrist Angle")) {
		Preferences::GetInstance()->PutDouble("Auto/scale/Scale Wrist Angle", 60);
	}
	//Switch Wrist Angle
	if (!Preferences::GetInstance()->ContainsKey("Auto/switch/Switch Wrist Angle")) {
		Preferences::GetInstance()->PutDouble("Auto/switch/Switch Wrist Angle", 50);
	}
	//Right Offset
	if (!Preferences::GetInstance()->ContainsKey("Auto/Right Offset")) {
		Preferences::GetInstance()->PutDouble("Auto/Right Offset", 0);
	}
}

// Called just before this Command runs the first time
void CheckPreferences::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CheckPreferences::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CheckPreferences::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CheckPreferences::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckPreferences::Interrupted() {

}
