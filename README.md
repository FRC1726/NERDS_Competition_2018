# FRC 1726 Competition Code 2018
## Understanding FRC Robot Code
Team 1726 uses the command-based robot code as a basis for their robot programs. This means that, instead of everything being handled in a global loop, actions are handled by runnable commands. 
## Special Files
### Robot.h/Robot.cpp
The Robot files handle all of the initialization of every other part of the Robot. Special commands, such as those that should only run once, and setup for initializing, running, and disable the various robot modes are also handled here.
### RobotMap.h
RobotMap is where all global variables are declared. These are variables such as port numbers, or joystick IDs which won't change or change very rarely. Variables which need to be changed on the fly should not be included here. They belong on the Dashboard.
### OI.h/OI.cpp
This file handles all of your Controllers and Triggers. You will define your controllers (Called Joysticks) and their buttons here, and assign commands to buttons and Triggers. OI also handles things such as grabbing axis and D-Pad values from the controllers.
## CommandBase.h/CommandBase/cpp
CommandBase is the parent class to all other commands. If you have any methods that all commands should have access to or run you should put them here. More importantly this is where you declare and define your subsystems as Static members. Doing so ensures that all commands have access to all of your Subsystem objects.
## Subsystems
Subsystems are the things that make up your robot. This is where you will declare all of the physical parts of the robot that you will interact with, for example the motor controllers that run the motors on your drivetrain. Subsystems also contain the methods that make those object work, for example a method to set the motor controller speed. You should ensure that all setup and initialization of any sensors, solenoids, and controllers are handled in a Subsystem's constructor.
## Commands
Commands make Subsystems do things. In general you should only use Commands to make the robot act, rather than calling a Subsystem's methods directly.
## CommandGroups
Command Groups handle the running of multiple Commands either in serial or parrallel. Use CommandGroups to string together groups of Commands into a larger Command.
## Triggers
Triggers will generally be used to run Commands when their conditions are true. This can be something like after reaching a certain value on a controller's trigger (which are axes, not buttons) or after a sensor reads a certain value. 
