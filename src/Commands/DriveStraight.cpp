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
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	double p = Preferences::GetInstance()->GetDouble("p", 0.1);
	double i = Preferences::GetInstance()->GetDouble("i", 0.0);
	double d = Preferences::GetInstance()->GetDouble("d", 0.0);
	drivetrain.setPID(p, i, d);
	drivetrain.setPoint(drivetrain.getAngle() );
	Leftinitial = drivetrain.getEncoderValue(DriveTrain::kLeft);
	Rightinitial = drivetrain.getEncoderValue(DriveTrain::kRight);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	SmartDashboard::PutNumber("TurnValue", drivetrain.getPIDOutput());
	double currentLeft = drivetrain.getEncoderValue(DriveTrain::kLeft);
	if (currentLeft > (Leftinitial + target)){
		drivetrain.arcadeDrive(-speed, drivetrain.getPIDOutput());
	}else if (currentLeft < (Leftinitial + target)){
		drivetrain.arcadeDrive(speed, drivetrain.getPIDOutput());
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
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	drivetrain.Stop();
}

double DriveStraight::DriveProfile(double input){
	if(fabs(input) <= Preferences::GetInstance()->GetDouble("Min Distance", .025)){
		return 0;
	}
	if(input > 0)
		return (Preferences::GetInstance()->GetDouble("Max Speed", 1) - Preferences::GetInstance()->GetDouble("Min Speed", 0)) * fabs(input) + Preferences::GetInstance()->GetDouble("Min Speed", 0);
	if(input < 0)
		return -((Preferences::GetInstance()->GetDouble("Max Speed", 1) - Preferences::GetInstance()->GetDouble("Min Speed", 0)) * fabs(input) + Preferences::GetInstance()->GetDouble("Min Speed", 0));
}
