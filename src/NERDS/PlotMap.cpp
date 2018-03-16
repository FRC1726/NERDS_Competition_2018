#include <NERDS/PlotMap.h>
#include <cmath>
#include <DriverStation.h>
#include <set>

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
	int source_y = floor(source.getY() / _precision);
	int destination_x = floor(destination.getX() / _precision);
	int destination_y = floor(destination.getY() / _precision);

	std::vector<PolarNum> movementPath;

	if(!isValid(source_x, source_y)){
		DriverStation::ReportWarning("Source Is Out Of Bounds!!!");
		return movementPath;
	}

	if(!isValid(destination_x, destination_y)){
		DriverStation::ReportWarning("Destination Is Out Of Bounds!!!");
		return movementPath;
	}

	if(isBlocked(source_x, source_y)){
		DriverStation::ReportWarning("Source Is Blocked!!!");
		return movementPath;
	}

	if(isBlocked(destination_x, destination_y)){
		DriverStation::ReportWarning("Destination Is Blocked!!!");
		return movementPath;
	}

	if(source == destination){
		DriverStation::ReportWarning("Already At Destination!!!");
		return movementPath;
	}

	bool closedList[_pathingGrid.size()][_pathingGrid[0].size()] = {false};
	std::set<std::pair<double, std::pair<int, int> > > openList;
	openList.insert(std::make_pair(0.0, std::make_pair(source_x, source_y)));

	while(!openList.empty()){
		auto point = *openList.begin();
		openList.erase(openList.begin());

		int x = openList.second.first;
		int y = openList.second.second;
		closedList[x][y];

		double g, h, f;

		for(int i = -1; i <= 1; i++){
			for(int j = -1; int j <= 1; j++){
				if(isValid(x + i, y + j) && (i != 0 || j != 0)){

				}
			}
		}
	}
}

bool PlotMap::isValid(int x, int y){
	return x < _pathingGrid.size() && y < _pathingGrid[0].size();
}

bool PlotMap::isBlocked(int x, int y){
	return _pathingGrid[x][y] == 0;
}
