#ifndef SRC_NERDS_POLARNUM_H_
#define SRC_NERDS_POLARNUM_H_

#include <utility>

class PolarNum {
public:
	PolarNum(double, double);
	PolarNum operator+(const PolarNum&);
private:
	double magnitude;
	double angle;
	std::pair<double, double> PolarToCartesian(double, double);
	PolarNum CartesianToPolar(double, double);
};

#endif /* SRC_NERDS_POLARNUM_H_ */
