#include "Geometry.h"
#include <cmath>

Point::Point(uint32_t ex, uint32_t wuy)
:x(ex), y(wuy)
{
}

float Point::distanceTo(struct Point& p)
{
	return sqrt(pow((p.y - y), 2) + pow((p.x - x), 2));
}
float Point::slopeTo(struct Point &p)
{
	return (float(p.y - y)/float(p.x - x));
}
