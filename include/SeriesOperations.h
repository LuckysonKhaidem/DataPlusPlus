#ifndef SERIESOPERATIONS_H
#define SERIESOPERATIONS_H

#ifdef __APPLE__
#define block_size(a) malloc_size(a)
#else
#define block_size(a) malloc_usable_size(a)
#endif

#include "Series.h"

Series operator+(double a, const Series& s);
Series operator-(double a, const Series& s);
Series operator*(double a, const Series& s);
Series operator/(double a, const Series& s);
vector<bool> operator&&(vector<bool> mask1, vector<bool> mask2);
vector<bool> operator||(vector<bool> mask1, vector<bool> mask2);

#endif