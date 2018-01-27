#include "DriveStraight.h"

DriveStraight::DriveStraight(double speed_in, double target_in, double TimeOut = 0) : CommandBase("DriveStraight") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis.get());
	if (TimeOut > 0){
		SetTimeout(TimeOut);
	}
	Requires(&drivetrain);
	speed = speed_in;
	target = target_in;
	if (!Preferences::GetInstance()->ContainsKey("Drive P")) {
		Preferences::GetInstance()->PutDouble("Drive P", 0.1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Drive I")) {
			Preferences::GetInstance()->PutDouble("Drive I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Drive D")) {
			Preferences::GetInstance()->PutDouble("Drive D", 0.0);
	}
}

// Called just before this Command runs the first time <3
void DriveStraight::Initialize() {
	double p = Preferences::GetInstance()->GetDouble("Drive P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Drive I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Drive D", 0.0);
	drivetrain.setPID(p, i, d);
	drivetrain.setPoint(drivetrain.getAngle() );
	drivetrain.setEnabled(true);
	Leftinitial = drivetrain.getEncoderValue(DriveTrain::kLeft);
	Rightinitial = drivetrain.getEncoderValue(DriveTrain::kRight);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	SmartDashboard::PutNumber("TurnValue", drivetrain.getPIDOutput());
	double currentLeft = drivetrain.getEncoderValue(DriveTrain::kLeft);
	if (currentLeft > (Leftinitial + target)){
		drivetrain.arcadeDrive(speed, drivetrain.getPIDOutput());
	}else if (currentLeft < (Leftinitial + target)){
		drivetrain.arcadeDrive(-speed, drivetrain.getPIDOutput());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	if (IsTimedOut()){
		return true;
	}

	double currentLeft =drivetrain.getEncoderValue(DriveTrain::kLeft);
	double currentRight = drivetrain.getEncoderValue(DriveTrain::kRight);
	if (currentLeft > (Leftinitial + target) - 4 && currentLeft < (Leftinitial + target) + 4){
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void DriveStraight::End() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	drivetrain.Stop();
	drivetrain.setEnabled(false);
}
