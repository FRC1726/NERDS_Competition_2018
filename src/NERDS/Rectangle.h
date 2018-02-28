#ifndef SRC_NERDS_RECTANGLE_H_
#define SRC_NERDS_RECTANGLE_H_

#include "NERDS/Cartesian.h"
#include "Obstacle.h"

class Rectangle : public Obstacle{
public:
	Rectangle(Cartesian, double, double);
	bool checkCollision(Obstacle&);
private:
	Cartesian P1;
	Cartesian P2;
};

#endif /* SRC_NERDS_RECTANGLE_H_ */
