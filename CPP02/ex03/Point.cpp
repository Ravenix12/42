
#include "Point.hpp"

Point::Point():x(0), y(0){}
Point::Point(Fixed a, Fixed b):x(a),y(b){}
Point::Point(float a, float b):x(Fixed(a)), y(Fixed(b)){}
Point::Point(const Point &dup): x(dup.x), y(dup.y) {}
Point &Point::operator=(const Point &other){
	(void)other;
	return *this;
}
Point::~Point(){}

const Fixed Point::getX() const{
	return x;
}
const Fixed Point::getY() const{
	return y;
}