#ifndef SRC_NERDS_PLOTMAP_H_
#define SRC_NERDS_PLOTMAP_H_
#include "Cartesian.h"
#include <vector>
#include "Obstacle.h"

class PlotMap {
public:
	PlotMap(Cartesian, Cartesian);
	PlotMap(Cartesian);
private:
	Cartesian min;
	Cartesian max;
	std::vector<Obstacle> obstacles;
};

#endif /* SRC_NERDS_PLOTMAP_H_ */
