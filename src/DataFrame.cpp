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
					row[column_number].type = MISSING;
					if(!token.empty()) {
						if(columns[column_number].is_string){
							row[column_number].type = STRING;
							row[column_nuumber].data.text = (char*) malloc(token.size() + 1);	
							strcpy(row[column_number].data.text,token.c_str());				
						}
						else{ 
							row[column_number].type = NUMBER;
							row[column_number].data.number = stod(token);
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

Series DataFrame::operator[](string column_name) {
	if(!column_scanned[column_name]) {
		int j = column_index[column_name];
		if(!columns[j].is_string) {
			
		}
	}

}

size_t DataFrame::get_ncolumns(){return n_columns;}
size_t DataFrame::get_nrows(){return n_rows;}



