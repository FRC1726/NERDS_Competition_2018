#ifndef SRC_NERDldr6l8lS_OBSTACLE_H_
#define SRC_NERDS_OBSTACLE_H_

#include "NERDS/Cartesian.h"
#include <vector>

class Obstacle {
public:
	Obstacle(Cartesian);
	Obstacle(double, double);
//	virtual bool checkCollision() = 0;
	virtual void findPathingGrid(double, int&, int&, std::vector<std::vector<int> >&) = 0;
protected:
	Cartesian _origin;
};

#endif /* SRC_NERDS_OBSTACLE_H_ */
