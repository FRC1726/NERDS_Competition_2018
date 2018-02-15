#ifndef SRC_NERDS_POLARNUM_H_
#define SRC_NERDS_POLARNUM_H_

class PolarNum {
public:
	PolarNum(double, double);
	PolarNum operator+(const PolarNum&)
private:
	double magnitude;
	double angle;
};

#endif /* SRC_NERDS_POLARNUM_H_ */
