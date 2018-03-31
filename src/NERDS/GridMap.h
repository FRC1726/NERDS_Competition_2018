#ifndef SRC_NERDS_GRIDMAP_H_
#define SRC_NERDS_GRIDMAP_H_

#include <NERDS/Cartesian.h>
#include <vector>
#include <NERDS/Obstacle.h>

class GridMap {
public:
	GridMap(Cartesian, Cartesian);
	GridMap(Cartesian);
private:
	Cartesian min;
	Cartesian max;
	std::vector<Obstacle> obstacles;
};

#endif /* SRC_NERDS_GRIDMAP_H_ */
