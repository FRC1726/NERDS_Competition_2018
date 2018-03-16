#include <NERDS/PlotMap.h>
#include <cmath>
#include <DriverStation.h>

PlotMap::PlotMap(double length, double height, double precision) :
	_length(length),
	_height(height),
	_precision(precision),
	_pathingGrid(floor(_height/precision), std::vector<int>(floor(_length/precision), 1))
{

}

void PlotMap::addObstacle(Obstacle* obstacle){
	std::unique_ptr<Obstacle> obs_ptr(obstacle);
	obstacles.push_back(std::move(obs_ptr));

	int x, y;
	std::vector<std::vector<int> > obstacleGrid;

	obstacle->findPathingGrid(_precision, x, y, obstacleGrid);
	for(unsigned int grid_x = 0; grid_x < obstacleGrid.size() && x + grid_x < _pathingGrid.size(); grid_x++){
		for(unsigned int grid_y = 0; grid_y < obstacleGrid[x].size() && y + grid_y < _pathingGrid[x + grid_x].size(); grid_y++){
			_pathingGrid[x + grid_x][y + grid_y] = obstacleGrid[grid_x][grid_y];
		}
	}
}

std::vector<PolarNum> PlotMap::generatePath(Cartesian source, Cartesian destination){
	int source_x = floor(source.getX() / _precision);
	int source_y = floor(source.getX() / _precision);
	int destination_x = floor(source.getX() / _precision);
	int _y = floor(source.getX() / _precision);

	std::vector<PolarNum> movementPath;

	if(!isValid(source)){
		DriverStation::ReportWarning("Source Is Out Of Bounds!!!");
		return movementPath;
	}

	if(!isValid(destination)){
		DriverStation::ReportWarning("Destination Is Out Of Bounds!!!");
		return movementPath;
	}

	if(isBlocked(source)){
		DriverStation::ReportWarning("Source Is Blocked!!!");
		return movementPath;
	}

	if(isBlocked(destination)){
		DriverStation::ReportWarning("Destination Is Blocked!!!");
		return movementPath;
	}

	if(source == destination){
		DriverStation::ReportWarning("Already At Destination!!!");
		return movementPath;
	}

	bool closedList[_pathingGrid.size()][_pathingGrid[0].size()];

	for()
}

bool PlotMap::isValid(Cartesian point){
	bool x = point.getX() <= _length && point.getX() >= 0;
	bool y = point.getY() <= _height && point.getY() >= 0;

	return x && y;
}

bool PlotMap::isBlocked(Cartesian point){
	int x = floor(point.getX() / _precision);
	int y = floor(point.getY() / _precision);

	return _pathingGrid[x][y] == 0;
}
