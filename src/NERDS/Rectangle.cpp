#include <NERDS/Rectangle.h>
#include "Cartesian.h"

Rectangle::Rectangle(Cartesian origin, double length, double width) :
	Obstacle(origin),
	P1(_origin.getX()-width/2, _origin.getY()-length/2),
	P2(_origin.getX()+width/2, _origin.getY()+length/2)
{

}
bool Rectangle::checkCollision(Obstacle& blockade){

}
