#ifndef MANDELBROT_HEADER_GUARD
#define MANDELBROT_HEADER_GUARD

#include <complex>

std::complex<double> mandelbrot_function(std::complex<double> &);
int inMandelbrotSet(std::complex<double>, uint64_t max_iters = 5);

#endif
