#include "Cartesian2D.h"
#include <iostream>
Cartesian2DPoint::Cartesian2DPoint(float x, float y, Cartesian2DPlane *pl)
:plane_x(x),plane_y(y), plane(pl)
{
}
Cartesian2DPoint::Cartesian2DPoint(uint32_t x, uint32_t y, Cartesian2DPlane *pl)
{
	plane = pl;
	plane_x = (float(x) - (plane->getWidth()/2.0));
	plane_y = -(float(y) - (plane->getHeight()/2.0));
	std::cout << "Constructor: " << plane_x << ' ' << plane_y << std::endl;
}
uint32_t Cartesian2DPoint::getX()
{
	return  (plane_x*plane->getXScaleFactor()) + (plane->getOriginX());
}
uint32_t Cartesian2DPoint::getY()
{
	return (-plane_y*plane->getYScaleFactor()) + (plane->getOriginY());
}

Cartesian2DPlane::Cartesian2DPlane(uint32_t w, uint32_t h, float zoom)
{
	width = w;
	height = h;
	originX = width/2;
	originY = height/2;
	XScaleFactor = zoom;
	YScaleFactor = (height/width) * XScaleFactor;
	// The above calculation makes sure that X and Y are
	// "stretched" to equal lengths, so that even if the
	// height and width are not same, we can have a grid
	// of squares.
}
void Cartesian2DPlane::zoomIn()
{
	XScaleFactor += ZOOM_STEP;
	YScaleFactor = (height/width) * XScaleFactor;
}
void Cartesian2DPlane::zoomOut()
{
	if(XScaleFactor <= 1) return;
	XScaleFactor -= ZOOM_STEP;
	YScaleFactor = (height/width) * XScaleFactor;
}
void Cartesian2DPlane::translateLeft() 	{	originX += TRANSLATE_STEP;	}
void Cartesian2DPlane::translateRight()	{	originX -= TRANSLATE_STEP;	}
void Cartesian2DPlane::translateUp()	{	originY -= TRANSLATE_STEP;	}
void Cartesian2DPlane::translateDown()	{	originY += TRANSLATE_STEP;	}
