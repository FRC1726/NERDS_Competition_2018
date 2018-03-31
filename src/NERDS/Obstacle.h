#ifndef SRC_NERDS_OBSTACLE_H_
#define SRC_NERDS_OBSTACLE_H_

#include <NERDS/Cartesian.h>

class Obstacle {
public:
	Obstacle(Cartesian);
	virtual bool checkCollision() = 0;
protected:
	Cartesian _origin;
};

#endif /* SRC_NERDS_OBSTACLE_H_ */
