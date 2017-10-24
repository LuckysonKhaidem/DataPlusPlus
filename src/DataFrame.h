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

class DataFrame {
	vector<column> columns;
	map<string, int> column_index;
	vector< vector<cell> > rows;
	bool is_read;
	size_t n_rows;
	size_t n_columns;
	bool checkString(string& token);
	int read_csv(string file_name,char delimiter);
public:
	DataFrame(string name, char delimiter);
	void print_row(int start, int end);
	void print_column(string column_name);
	cell* get_column(string column_name);
	void add_row(vector<cell>& row);
	// void add_column(string column_name, cell* series);
	// void add_column(string column_name, cell replicated_entry);
	size_t get_ncolumns();
	size_t get_nrows();
};

#endif