#include "GrabAndReturn.h"

#include "Subsystems/DriveTrain.h"
#include "Commands/DriveByDistance.h"
#include "Commands/TurnByAngle.h"
#include "Commands/ToggleGrabber.h"
GrabAndReturn::GrabAndReturn() : CommandGroup("Grab and Return") {
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
	AddSequential(new DriveByDistance(80));
	AddSequential(new ToggleGrabber());
	AddSequential(new TurnByAngle(180));
	AddSequential(new DriveByDistance(80));
}
