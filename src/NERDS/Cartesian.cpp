#include <NERDS/Cartesian.h>
#include <NERDS/Polar.h>

#include <cmath>

Cartesian::Cartesian(double x, double y) {
	_x = x;
	_y = y;
}

Cartesian Cartesian::operator+(const Cartesian& other){
	double x = this->_x + other._x;
	double y = this->_y + other._y;
	Cartesian out(x , y);
	return out;
}
Cartesian Cartesian::operator-(const Cartesian& other){
	double x = this->_x - other._x;
	double y = this->_y - other._y;
	Cartesian out(x , y);
	return out;
}
Cartesian Cartesian::operator/(const Cartesian& other){
	Polar thisPolar = this->toPolar();
	Polar otherPolar = other.toPolar();
	Polar out = thisPolar / otherPolar;
	return out.toCartesian();
}
Cartesian Cartesian::operator*(const Cartesian& other){
	Polar thisPolar = this->toPolar();
	Polar otherPolar = other.toPolar();
	Polar out = thisPolar * otherPolar;
	return out.toCartesian();
}

Polar Cartesian::toPolar() const{
	double mag = pow((pow(_x, 2) + pow(_y, 2)), 0.5);
	double ang;
	if(_x == 0 && _y == 0){
		ang = 0;
	}else{
		ang = atan2(_y, _x);
	}
	Polar out(mag, ang * 180 / 3.14159);
	return out;
}

double Cartesian::getX(){
	return _x;
}

double Cartesian::getY(){
	return _y;
}
