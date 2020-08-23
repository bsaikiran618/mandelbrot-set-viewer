#ifndef CARTESIAN_2D_HEADER
#define CARTESIAN_2D_HEADER
#define ZOOM_STEP 0.1
#define TRANSLATE_STEP 5
#include <cstdint>
class Cartesian2DPlane
{
	//This is a simple cartesian plane;
	uint32_t width, height;
	uint32_t originX, originY;
	double XScaleFactor, YScaleFactor;
	public:
	Cartesian2DPlane(uint32_t, uint32_t, double); //This last parameter is the scale factor. Increase to zoom in, decrease to zoom out
	double getXScaleFactor(){return XScaleFactor;}
	double getYScaleFactor(){return YScaleFactor;}
	void zoomIn();
	void zoomOut();
	void translateLeft();
	void translateRight();
	void translateUp();
	void translateDown();
	uint32_t getWidth()		{return width;}
	uint32_t getHeight()	{return height;}
	uint32_t getOriginX()	{return originX;}
	uint32_t getOriginY()	{return originY;}
};
class Cartesian2DPoint
{
	double plane_x,plane_y;
	Cartesian2DPlane *plane;

	public:
	Cartesian2DPoint(double, double, Cartesian2DPlane *);
	uint32_t getX();
	uint32_t getY();
};
#endif
