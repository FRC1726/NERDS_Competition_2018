#ifndef SRC_NERDS_POLARNUM_H_
#define SRC_NERDS_POLARNUM_H_

#include <utility>

class Cartesian;

class PolarNum {
public:
	PolarNum(double, double);

	PolarNum operator+(const PolarNum&);
	PolarNum operator-(const PolarNum&);
	PolarNum operator/(const PolarNum&);
	PolarNum operator*(const PolarNum&);

	Cartesian toCartesian() const;
private:
	double magnitude;
	double angle;

	PolarNum CartesianToPolar(double, double);
};

#endif /* SRC_NERDS_POLARNUM_H_ */
