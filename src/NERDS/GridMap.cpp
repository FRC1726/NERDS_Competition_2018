#include <NERDS/GridMap.h>

GridMap::GridMap(Cartesian minimum, Cartesian maximum) :
	min(minimum),
	max(maximum)
{

}

GridMap::GridMap(Cartesian maximum) :
	min(0 , 0),
	max(maximum)
{

}
