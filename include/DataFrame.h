#ifndef DATAFRAME_H
#define DATAFRAME_H


#include "Primitives.h"
#include "Series.h"

using namespace std;
class DataFrame {

	vector<column> columns;
	map<string, int> column_index;
	vector< vector<cell> > rows;
	vector<Series> column_view;
	map<string, bool> column_scanned;
	bool is_read;
	int n_rows;
	int n_columns;

	bool checkString(string& token);
	int read_csv(string file_name,char delimiter);

public:
	DataFrame(string name, char delimiter);
	// vector<cell>& operator[](int index);
	Series operator[](string column_name);
	// Series operator[](int column_index);
	friend ostream& operator<<(ostream& os, const DataFrame& df);
	int get_ncolumns() const;
	int get_nrows() const;
};

#endif
