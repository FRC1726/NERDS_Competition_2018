#ifndef SRC_NERDS_POLAR_H_
#define SRC_NERDS_POLAR_H_

#include <utility>

class Cartesian;

class Polar {
public:
	Polar(double = 0, double = 0);

	Polar operator+(const Polar&);
	Polar operator-(const Polar&);
	Polar operator/(const Polar&);
	Polar operator*(const Polar&);

	Cartesian toCartesian() const;
private:
	double magnitude;
	double angle;

	Polar CartesianToPolar(double, double);
};

#endif /* SRC_NERDS_POLAR_H_ */
