#include "DataFrame.h"

using namespace std;

bool DataFrame:: checkString(string& token){
	try {
		stod(token);
	}
	catch(const invalid_argument& ii) {
		return true;
	}

	return false;

}

DataFrame::DataFrame(string file_name, char delimiter) 
{
	this->is_read = false;
	this->n_rows = 0;
	this->n_columns = 0;
	read_csv(file_name, delimiter);
}

int DataFrame::read_csv(string file_name, char delimiter) {
	if(!is_read) is_read = true;
	else return -1;

	bool first_line = true;
	int column_number;
	ifstream myfile (file_name);
	string line, token;

	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			
			istringstream line_stream(line);
			if(first_line) {
				while(getline(line_stream, token, delimiter)) {
					column col;
					col.column_name = token;
					col.data_type_determined = false;
					columns.push_back(col);
					column_index[token] = n_columns;
					n_columns++;
				}
				
				first_line = false;
			}
			else {
				column_number = 0;
				vector<cell> row(n_columns);
				while(getline(line_stream, token, delimiter)) {
					if(!columns[column_number].data_type_determined && !token.empty()) {
							
							columns[column_number].is_string = checkString(token);
							columns[column_number].data_type_determined = true;
							
					}
					
					
					row[column_number].string_data.assign("NULL");
					row[column_number].numerical_data = numeric_limits<double>::infinity();
					if(!token.empty()) {
						if(columns[column_number].is_string) row[column_number].string_data.assign(token);					
						else{ 
							try{
								row[column_number].numerical_data = stod(token);
							}
							catch(const invalid_argument& ii) {
								row[column_number].string_data = token;
							}

						}
					}
					column_number++;
					
				}
				rows.push_back(row);
				n_rows++;
			}

		}
	}
	else return 1;
	cout <<"ROWS: "<<n_rows<<" COLUMNS: "<<n_columns<<"\n";
	return 0;

}

void DataFrame::print_column(string column_name) {
	int j = column_index[column_name];
	int i;
	for( i = 0 ; i < n_rows ; i ++) {
		if(columns[j].is_string) cout << rows[i][j].string_data;
		else cout << rows[i][j].numerical_data;
		cout<<"\n";
	}
	

}
void DataFrame::print_row(int start, int end) 
{
	int i,j;
	vector<column>::iterator it;
	it = columns.begin();
	while(it != columns.end()) {
			cout<<it->column_name<<",";
			it++;		
	}
	cout<<"\n";

	for(i = start; i < end;i++){
		for(j = 0; j < n_columns;j++){
			if(columns[j].is_string) cout<<rows[i][j].string_data<<",";
			else  cout<<rows[i][j].numerical_data<<",";
		}
		cout <<"\n";
	}
}

cell* DataFrame::get_column(string column_name) {
		int i;
		int j = column_index[column_name]; 
		cell* cells = new cell[n_rows];

		for(i = 0;i<n_rows;i++){
			cells[i].string_data = rows[i][j].string_data;
			cells[i].numerical_data = rows[i][j].numerical_data;
		}
		return cells;
	}
void DataFrame::add_row(vector<cell>& row) {
	if(row.size() == n_columns){
		rows.push_back(row);
		n_rows++;
	}
}
// void DataFrame::add_column(string column_name, cell replicated_entry, bool is_string) {
// 	column col;
// 	col.column_name = column_name;
// 	col.data_type_determined = true;
// 	col.is_string = is_string;
// 	column_index[column_name] = n_columns;
// 	n_columns++;

// 	int i;
// 	for(i =0 ;i <n_rows;i++)



// }
size_t DataFrame::get_ncolumns(){return n_columns;}
size_t DataFrame::get_nrows(){return n_rows;}



