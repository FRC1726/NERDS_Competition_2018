#ifndef SRC_NERDS_PLOTMAP_H_
#define SRC_NERDS_PLOTMAP_H_
#include "NERDS/Cartesian.h"
#include <vector>
#include "NERDS/Obstacle.h"
#include <memory>
#include "PolarNum.h"
#include "Cartesian.h"

class PlotMap {
public:
	PlotMap(double, double, double);
	void addObstacle(Obstacle*);
	std::vector<PolarNum> generatePath(Cartesian, Cartesian);
private:
	double _length;
	double _height;
	double _precision;

	std::vector<std::vector<int> > _pathingGrid;
	std::vector<std::unique_ptr<Obstacle> > obstacles;

	bool isValid(int, int);
	bool isBlocked(int, int);
};

#endif /* SRC_NERDS_PLOTMAP_H_ */
