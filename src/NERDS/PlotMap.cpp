#include <NERDS/PlotMap.h>
#include <cmath>

PlotMap::PlotMap(Cartesian minimum, Cartesian maximum) :
	min(minimum),
	max(maximum)
{

}

PlotMap::PlotMap(Cartesian maximum) :
	min(0 , 0),
	max(maximum)
{

}

void PlotMap::addObstacle(Obstacle* obstacle){
	std::unique_ptr<Obstacle> obs_ptr(obstacle);
	obstacles.push_back(std::move(obs_ptr));
}

std::vector<std::vector<int> > PlotMap::generateGrid(double precision){
	int length = floor((max.getX() + min.getX()) / precision);
	int width = floor((max.getY() + min.getY()) / precision);
}
