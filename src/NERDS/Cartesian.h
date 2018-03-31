#ifndef SRC_NERDS_CARTESIAN_H_
#define SRC_NERDS_CARTESIAN_H_

#include <utility>

class Polar;

class Cartesian {
public:
	Cartesian(double = 0, double = 0);

	double getX();
	double getY();

	Cartesian operator+(const Cartesian&);
	Cartesian operator-(const Cartesian&);
	Cartesian operator/(const Cartesian&);
	Cartesian operator*(const Cartesian&);

	Polar toPolar() const;
private:
	double _x;
	double _y;
};

#endif /* SRC_NERDS_CARTESIAN_H_ */
