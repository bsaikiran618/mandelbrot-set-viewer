#include "Cartesian2D.h"

Cartesian2DPoint::Cartesian2DPoint(uint32_t scr_x, uint32_t scr_y, Cartesian2DPlane *plane)
{
	//FLIP THE Y AXIS
	y = -scr_y;
	//TRANSLATE BOTH AXES
	x = scr_x + (plane->getWidth()/2);
	y = scr_y + (plane->getHeight()/2);
	//SCALE THE POINT
	x *= plane->getXScaleFactor();
	y *= plane->getYScaleFactor();
}

Cartesian2DPlane::Cartesian2DPlane(uint32_t w, uint32_t h, double zoom)
{
	width = w;
	height = h;
	XScaleFactor = zoom;
	YScaleFactor = (height/width) * XScaleFactor;
	// The above calculation makes sure that X and Y are
	// "stretched" to equal lengths, so that even if the
	// height and width are not same, we can have a grid
	// of squares.
}
