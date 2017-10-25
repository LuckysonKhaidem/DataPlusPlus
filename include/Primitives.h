#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <string>
using namespace std;


typedef struct  {
	string string_data;
	double numerical_data;
}cell;

typedef struct  {
	string column_name;
	bool is_string;
	bool data_type_determined;
} column;


#endif