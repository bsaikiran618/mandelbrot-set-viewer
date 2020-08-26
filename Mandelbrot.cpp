#include "Mandelbrot.h"

bool inMandelbrotSet(std::complex<double> point, uint64_t max_iters)
{
	for(uint64_t i=0;i<max_iters;i++)
	{
		if(std::abs(point) > 2) return false;
		point = std::pow(point, 2) + point;
	}
	return true;
}
