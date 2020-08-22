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
	uint32_t scr_x,scr_y;
	public:
	Cartesian2DPoint(double, double, Cartesian2DPlane *);
	uint32_t getX(){return scr_x;}
	uint32_t getY(){return scr_y;}
};
#endif
