#ifndef SRC_NERDS_POLARNUM_H_
#define SRC_NERDS_POLARNUM_H_

#include <utility>

class Cartesian;

class PolarNum {
public:
	PolarNum(double = 0, double = 0);

	PolarNum operator+(const PolarNum&);
	PolarNum operator-(const PolarNum&);
	PolarNum operator/(const PolarNum&);
	PolarNum operator*(const PolarNum&);

	Cartesian toCartesian() const;

	double getMagnitude();
	double getAngle();
private:
	double magnitude;
	double angle;

	PolarNum CartesianToPolar(double, double);
};

#endif /* SRC_NERDS_POLARNUM_H_ */
