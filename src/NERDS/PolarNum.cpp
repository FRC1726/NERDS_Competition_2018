#include <NERDS/PolarNum.h>

PolarNum::PolarNum(double magnitude ,double angle) {
	this->magnitude = magnitude;
	this->angle = angle;
}

PolarNum PolarNum::operator+(const PolarNum& other)

