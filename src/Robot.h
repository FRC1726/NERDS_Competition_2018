#ifndef ROBOT_H
#define ROBOT_H

#include <memory>
#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
private:
	std::shared_ptr<Command> initClaw;
	std::shared_ptr<Command> tracking;
	std::shared_ptr<Command> autonomousCommand;
	frc::SendableChooser<int> initialPosition;
};

#endif //ROBOT_H
