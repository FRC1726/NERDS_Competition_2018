#ifndef SRC_NERDS_RECTANGLE_H_
#define SRC_NERDS_RECTANGLE_H_

#include "NERDS/Cartesian.h"

class Rectangle {
public:
	Rectangle(Cartesian, Cartesian);
private:
	Cartesian P1;
	Cartesian P2;
};

#endif /* SRC_NERDS_RECTANGLE_H_ */
