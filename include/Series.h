#ifndef SERIES_H
#define SERIES_H

#include "Primitives.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <limits>
#include <map>
#include <string>
#include <math.h>

using namespace std;
class Series {
	int type;
	int size;
	string series_name;
	vector<cell> cells;
	map<string, double> statistics;
	map<string, bool> calculated;

public:
	Series(int type, int size, string series_name, vector<cell>& cells);
	Series(int type, int size, string series_name, cell* cells);
	Series(double* arr, int size);
	// Series(double* arr, int size);
	// Series(char* arr[]);
	Series(char** arr, int size);

	~Series();

	cell operator[](int index);
	void print();
	Series operator+(Series b);
	Series operator-(Series b);
	Series operator*(Series b);
	Series operator/(Series b);

	// Series operator+(double num);
	// Series operator-(double num);
	// Series operator*(double num);
	// Series operator/(double num);

	double mean();
	double std();
	double sum();

	// friend ostream& operator<<(ostream& os, const Series& s);
	int getSize();
	int getType();
	string getName();
};

#endif