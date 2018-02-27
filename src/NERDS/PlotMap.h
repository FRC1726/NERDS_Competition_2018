#ifndef SRC_NERDS_PLOTMAP_H_
#define SRC_NERDS_PLOTMAP_H_
#include <Cartesian.h>
#include <vector>

class PlotMap {
public:
	PlotMap(Cartesian, Cartesian);
	PlotMap(Cartesian);
private:
	Cartesian min;
	Cartesian max;
	vector<Obstacle> obstacles;
};

#endif /* SRC_NERDS_PLOTMAP_H_ */
