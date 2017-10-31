#ifndef MATHUTIL_H
#define MATHUTIL_H

#include <cmath>
#include <iostream>
#include <vector>
#include "Primitives.h"
#include "Series.h"


namespace mathutil{
	
	Series series_sin(const Series& s);
	Series series_cos(const Series& s);
	Series series_tan(const Series& s);
	Series series_exp(const Series& s);
	Series series_log(const Series& s);
	Series series_log10(const Series& s);
	Series series_pow(const Series& s, int power);
} 

#endif 
