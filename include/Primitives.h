#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>
#include <limits>
#include <regex>
#include <string.h>
#include <cmath>

using namespace std;

enum data_type {NUMBER, STRING, MISSING};

typedef struct  {
	int type;
	union {
		double number;
		char* text;
	}data;
}cell;

typedef struct  {
	string column_name;
	bool is_string;
	int type;
	bool data_type_determined;
} column;

#endif
