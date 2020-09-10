#include "Mandelbrot.h"
#include <iostream>

bool inMandelbrotSet(std::complex<double> point, uint64_t max_iters)
{
	std::complex<double> initial = point;
	for(uint64_t i=0;i<max_iters;i++)
	{
		if(std::abs(point) > 2) return false;
		point = std::pow(point, 2) + initial;
	}
	return true;
}
