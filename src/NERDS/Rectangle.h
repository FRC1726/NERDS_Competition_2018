#ifndef SRC_NERDS_RECTANGLE_H_
#define SRC_NERDS_RECTANGLE_H_

#include "NERDS/Cartesian.h"
#include "NERDS/Obstacle.h"

class Rectangle : public Obstacle{
public:
	Rectangle(Cartesian, double, double);
	Rectangle(Cartesian, Cartesian);
	//bool checkCollision(Obstacle);
	void findPathinGrid(double, int&, int&, std::vector<std::vector<int> >&);
private:
	Cartesian P1;
	Cartesian P2;
};

#endif /* SRC_NERDS_RECTANGLE_H_ */
