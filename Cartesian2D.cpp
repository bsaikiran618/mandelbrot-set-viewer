#include "Cartesian2D.h"

Cartesian2DPoint::Cartesian2DPoint(double x, double y, Cartesian2DPlane *plane)
{
	//FLIP THE Y AXIS
	//TRANSLATE BOTH AXES
	//SCALE THE POINT
	scr_x = x*plane->getXScaleFactor() + (plane->getWidth()/2);
	scr_y = -y*plane->getYScaleFactor() + (plane->getHeight()/2);
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
