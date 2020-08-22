#ifndef CARTESIAN_2D_HEADER
#define CARTESIAN_2D_HEADER
#include <cstdint>
class Cartesian2DPlane
{
	//This is a simple cartesian plane;
	uint32_t width, height;
	double XScaleFactor, YScaleFactor;
	public:
	Cartesian2DPlane(uint32_t, uint32_t, double);
	double getXScaleFactor(){return XScaleFactor;}
	double getYScaleFactor(){return YScaleFactor;}
	uint32_t getWidth(){return width;}
	uint32_t getHeight(){return height;}
};
class Cartesian2DPoint
{
	long double x,y;
	public:
	Cartesian2DPoint(uint32_t , uint32_t , Cartesian2DPlane *);
	//This constructor converts the given screen coordinates to cartesian points of a cartesian plane
};
#endif
