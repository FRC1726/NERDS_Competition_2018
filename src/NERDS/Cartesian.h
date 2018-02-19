#ifndef SRC_NERDS_CARTESIAN_H_
#define SRC_NERDS_CARTESIAN_H_

#include <utility>

class PolarNum;

class Cartesian {
public:
	Cartesian(double, double);

	Cartesian operator+(const Cartesian&);
	Cartesian operator-(const Cartesian&);
	Cartesian operator/(const Cartesian&);
	Cartesian operator*(const Cartesian&);

	PolarNum toPolar() const;
private:
	double _x;
	double _y;
};

#endif /* SRC_NERDS_CARTESIAN_H_ */
