#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <string>
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