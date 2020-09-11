#include "Mandelbrot.h"

int inMandelbrotSet(std::complex<double> point, uint64_t max_iters)
{
	std::complex<double> initial = point;
	int count = 0;
	for(uint64_t i=0;i<max_iters;i++)
	{
		if(std::abs(point) > 2) return count;
		point = std::pow(point, 2) + initial;
		count++;
	}
	return -1;
}
