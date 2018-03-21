#include <NERDS/Rectangle.h>
#include <vector>
#include <cmath>

Rectangle::Rectangle(Cartesian origin, double length, double width) :
	Obstacle(origin),
	P1(_origin.getX()-width/2, _origin.getY()-length/2),
	P2(_origin.getX()+width/2, _origin.getY()+length/2)
{

}

Rectangle::Rectangle(Cartesian a, Cartesian b) :
	Obstacle((a.getX() + b.getX()) / 2,(a.getY() + b.getY()) / 2),
	P1(a),
	P2(b)
{

}

void Rectangle::findPathingGrid(double precision, int& x, int& y, std::vector<std::vector<int> > &grid){
	int length = floor((P2.getX() + P1.getX()) / precision);
	int width = floor((P2.getY() + P1.getY()) / precision);
	std::vector<std::vector<int> > pathingGrid(width, std::vector<int>(length, 0) );
	grid = pathingGrid;
	x = floor(P1.getX() / precision);
	y = floor(P1.getY() / precision);
}

