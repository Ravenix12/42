

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
	private:
	const Fixed x;
	const Fixed y;

	public:
	Point();
	Point(Fixed a, Fixed b);
	Point(float a, float b);
	Point(const Point &dup);
	Point &operator=(const Point &other);
	~Point();

	const Fixed getX() const;
	const Fixed getY() const;
};

float area(Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif