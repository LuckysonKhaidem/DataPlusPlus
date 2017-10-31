#ifndef DATAFRAME_H 
#define DATAFRAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>
#include <limits>
#include <regex>
#include "Primitives.h"
#include "Series.h"

class DataFrame {
	vector<column> columns;
	map<string, int> column_index;
	vector< vector<cell> > rows;
	map<string, Series> column_view;
	map<string, bool> column_scanned;
	bool is_read;
	size_t n_rows;
	size_t n_columns;

	bool checkString(string& token);
	int read_csv(string file_name,char delimiter);
public:
	DataFrame(string name, char delimiter);
	// vector<cell>& operator[](int index);
	Series operator[](string column_name);
	Series operator[](int column_index);
	size_t get_ncolumns();
	size_t get_nrows();
};

#endif