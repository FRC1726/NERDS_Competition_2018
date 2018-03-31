#include <CommandGroups/DriveThroughPath.h>

#include <Commands/TurnToAngle.h>
#include <Commands/DriveByDistance.h>

DriveThroughPath::DriveThroughPath(std::vector<Polar> path){
	for(auto point : path){
		AddSequential(new TurnToAngle(point.getAngle()));
		AddSequential(new DriveByDistance(point.getMagnitude()));
	}
}
