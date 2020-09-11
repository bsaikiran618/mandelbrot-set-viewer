#ifndef CARTESIAN_2D_HEADER
#define CARTESIAN_2D_HEADER
#define ZOOM_STEP 2
#define TRANSLATE_STEP 5
#include <cstdint>
class Cartesian2DPlane
{
	//This is a simple cartesian plane;
	uint64_t width, height;
	uint64_t originX, originY;
	double XScaleFactor, YScaleFactor;
	public:
	Cartesian2DPlane(uint64_t, uint64_t, double); //This last parameter is the scale factor. Increase to zoom in, decrease to zoom out
	void zoomIn();
	void zoomOut();
	void translateLeft();
	void translateRight();
	void translateUp();
	void translateDown();
	uint64_t getWidth()		{return width;}
	uint64_t getHeight()	{return height;}
	uint64_t getOriginX()	{return originX;}
	uint64_t getOriginY()	{return originY;}
	double getXScaleFactor(){return XScaleFactor;}
	double getYScaleFactor(){return YScaleFactor;}
};
class Cartesian2DPoint
{
	double plane_x,plane_y;
	Cartesian2DPlane *plane;

	public:
	Cartesian2DPoint (double, double, Cartesian2DPlane 		*); //This takes a cartesian point.
	Cartesian2DPoint (uint64_t , uint64_t, Cartesian2DPlane 		*); //This takes a screen coordinate and converts it into a point.
	uint64_t getOnScreenX();
	uint64_t getOnScreenY();
	double getPlaneX() {return plane_x;}
	double getPlaneY() {return plane_y;}
};
#endif
