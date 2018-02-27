#include <NERDS/PlotMap.h>

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
