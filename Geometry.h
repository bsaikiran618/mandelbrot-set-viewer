#ifndef GEOMETRY
		#include "Window.h"
		#include <utility>
		struct Point
		{
			uint32_t x,y;
			Point(uint32_t ex, uint32_t wuy);
			float distanceTo(struct Point &p);
			float slopeTo(struct Point &p);
			std::pair<uint32_t, uint32_t>toPixels(Window &w);
		};
#endif
