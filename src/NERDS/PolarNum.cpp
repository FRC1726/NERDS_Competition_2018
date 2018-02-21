#include <NERDS/PolarNum.h>

#include "Cartesian.h"

#include <cmath>

PolarNum::PolarNum(double mag, double degrees) {
	magnitude = mag;
	angle = degrees * 3.14159 / 180;
}

PolarNum PolarNum::operator+(const PolarNum& other){
	Cartesian thisCartesian = this->toCartesian();
	Cartesian otherCartesian = other.toCartesian();
	Cartesian out = thisCartesian + otherCartesian;
	return out.toPolar();
}
PolarNum PolarNum::operator-(const PolarNum& other){
	Cartesian thisCartesian = this->toCartesian();
	Cartesian otherCartesian = other.toCartesian();
	Cartesian out = thisCartesian - otherCartesian;
	return out.toPolar();
}

PolarNum PolarNum::operator/(const PolarNum& other){
	double mag = this->magnitude / other.magnitude;
	double ang = this->angle - other.angle;
	ang = ang * 3.14159 / 180;
	PolarNum out(mag, ang);
	return out;
}

PolarNum PolarNum::operator*(const PolarNum& other){
	double mag = this->magnitude * other.magnitude;
	double ang = this->angle + other.angle;
	ang = ang * 3.14159 / 180;
	PolarNum out(mag, ang);
	return out;
}

Cartesian PolarNum::toCartesian() const{
	double x = magnitude * cos(angle);
	double y = magnitude * sin(angle);

	Cartesian out(x , y);
	return out;
}

double PolarNum::getMagnitude(){
	return magnitude;
}

double PolarNum::getAngle(){
	return angle;
}
