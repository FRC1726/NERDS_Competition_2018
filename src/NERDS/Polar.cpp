#include <NERDS/Polar.h>
#include "Cartesian.h"

#include <cmath>

Polar::Polar(double mag, double degrees) {
	magnitude = mag;
	angle = degrees * 3.14159 / 180;
}

Polar Polar::operator+(const Polar& other){
	Cartesian thisCartesian = this->toCartesian();
	Cartesian otherCartesian = other.toCartesian();
	Cartesian out = thisCartesian + otherCartesian;
	return out.toPolar();
}
Polar Polar::operator-(const Polar& other){
	Cartesian thisCartesian = this->toCartesian();
	Cartesian otherCartesian = other.toCartesian();
	Cartesian out = thisCartesian - otherCartesian;
	return out.toPolar();
}

Polar Polar::operator/(const Polar& other){
	double mag = this->magnitude / other.magnitude;
	double ang = this->angle - other.angle;
	ang = ang * 3.14159 / 180;
	Polar out(mag, ang);
	return out;
}

Polar Polar::operator*(const Polar& other){
	double mag = this->magnitude * other.magnitude;
	double ang = this->angle + other.angle;
	ang = ang * 3.14159 / 180;
	Polar out(mag, ang);
	return out;
}

Cartesian Polar::toCartesian() const{
	double x = magnitude * cos(angle);
	double y = magnitude * sin(angle);

	Cartesian out(x , y);
	return out;
}

double Polar::getAngle(){
	return angle * 180 / 3.14159;
}

double Polar::getMagnitude(){
	return magnitude;
}
