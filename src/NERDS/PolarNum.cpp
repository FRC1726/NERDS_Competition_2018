#include <NERDS/PolarNum.h>

#include <cmath>

PolarNum::PolarNum(double mag, double degrees) {
	magnitude = mag;
	angle = degrees * 3.14159 / 180;
}

PolarNum PolarNum::operator+(const PolarNum& other){
	auto thisCartesian = PolarToCartesian(this->magnitude, this->angle);
	thisCartesian.first
}

std::pair<double, double> PolarNum::PolarToCartesian(double mag, double ang){
	double x = mag * cos(ang);
	double y = mag * sin(ang);

	return std::make_pair(x, y);
}

PolarNum PolarNum::CartesianToPolar(double x, double y){
	double mag = pow((pow(x, 2) + pow(y, 2)), 0.5);
	double ang = atan(y / x);
	PolarNum out(mag, ang * 180 / 3.14159);
	return out;
}
