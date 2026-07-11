
#include "Point.hpp"

float area(float x1, float y1, float x2, float y2, float x3, float y3){
	float ret = (x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0;
	return ret < 0 ? ret : -ret;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	
	float x1 = a.getX().toFloat();
	float y1 = a.getY().toFloat();
	float x2 = b.getX().toFloat();
	float y2 = b.getY().toFloat();
	float x3 = c.getX().toFloat();
	float y3 = c.getY().toFloat();
	float x  = point.getX().toFloat();
	float y  = point.getY().toFloat();

	float A = area (x1, y1, x2, y2, x3, y3);
	float A1 = area (x, y, x2, y2, x3, y3);
	float A2 = area (x1, y1, x, y, x3, y3);
	float A3 = area (x1, y1, x2, y2, x, y);
	return ((A == A1 + A2 + A3) && A1 != 0 && A2 != 0 && A3 != 0);
}
