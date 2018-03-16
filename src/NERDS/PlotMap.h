#ifndef SRC_NERDS_PLOTMAP_H_
#define SRC_NERDS_PLOTMAP_H_
#include "NERDS/Cartesian.h"
#include <vector>
#include "NERDS/Obstacle.h"
#include <memory>

class PlotMap {
public:
	PlotMap(Cartesian, Cartesian);
	PlotMap(Cartesian);
	void addObstacle(Obstacle*);
private:
	Cartesian min;
	Cartesian max;
	std::vector<std::unique_ptr<Obstacle> > obstacles;
	std::vector<std::vector<int> > generateGrid(double);
};

#endif /* SRC_NERDS_PLOTMAP_H_ */
