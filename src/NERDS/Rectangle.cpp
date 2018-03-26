#include <NERDS/Rectangle.h>
#include <cmath>

Rectangle::Rectangle(Cartesian origin, double length, double width) :
	Obstacle(origin),
	P1(_origin.getX()-width/2, _origin.getY()-length/2),
	P2(_origin.getX()+width/2, _origin.getY()+length/2),
	P3(_origin.getX()+width/2, _origin.getY()-length/2),
	P4(_origin.getX()-width/2, _origin.getY()+length/2)
{

}

bool checkCollision(Obstacle other){
	double half_rect = P1.getX() + P2.getX();
	double length = half_rect - (other.getX + other.getX);
	double gap = length - half_rect;

	if(gap > 0){
		return false;
	}
	else if(gap == 0){
		return true;
	}
	else if(gap < 0){
		return true;
	}
}

Projection getProjection(double degrees){
	double radians = degrees * 3.14159 / 180;
	double x1 = (P1.getX()) * cos(radians) - (P1.getY()) * sin(radians);
	double y1 = (P1.getX()) * sin(radians) + (P1.getY()) * cos(radians);

	double x2 = (P2.getX()) * cos(radians) - (P2.getY()) * sin(radians);
	double y2 = (P2.getX()) * sin(radians) + (P2.getY()) * cos(radians);

	double x3 = (P3.getX()) * cos(radians) - (P3.getY()) * sin(radians);
	double y3 = (P3.getX()) * sin(radians) + (P3.getY()) * cos(radians);

	double x4 = (P4.getX()) * cos(radians) - (P4.getY()) * sin(radians);
	double y4 = (P4.getX()) * sin(radians) + (P4.getY()) * cos(radians);
}
