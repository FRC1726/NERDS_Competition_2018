#ifndef DriveThroughPoints_H
#define DriveThroughPoints_H

#include <Commands/CommandGroup.h>
#include <utility>
#include <vector>

class DriveThroughPoints : public CommandGroup {
public:
	DriveThroughPoints(std::vector<std::pair<double, double> >);
};
#endif  // DriveThroughPoints_H
