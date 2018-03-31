#ifndef MappedDrive_H
#define MappedDrive_H

#include <Commands/CommandGroup.h>
#include <vector>
#include <NERDS/Polar.h>

class DriveThroughPath : public CommandGroup {
public:
	DriveThroughPath(std::vector<Polar>);
};

#endif  // MappedDrive_H
