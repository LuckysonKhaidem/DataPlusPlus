#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>
#include <limits>
using namespace std;

typedef struct cell {
	string string_data;
	double numerical_data;
}cell;

typedef struct column {
	string column_name;
	bool is_string;
	bool data_type_determined;
}column;


bool is_string(string& token){
	try{
		stod(token);

	}
	catch (const invalid_argument& ii) {
		return true;
	}
	return false;

}

class DataFrame{
	vector<column> columns;
	map<string, int> column_index;
	map< string, vector<cell> > data_frame;
	bool is_read;
	size_t n_rows;
	size_t n_columns;


public:
	CSVReader() {
		is_read = false;
		n_rows = 0;
		n_columns = 0;
	}
	int read_csv(string file_name, char delimiter) {
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
					while(getline(line_stream, token, delimiter)) {
						if(!columns[column_number].data_type_determined && !token.empty()) {
								columns[column_number].is_string = is_string(token);
								columns[column_number].data_type_determined = true;
						}
						cell entry;
						entry.string_data.assign("NULL");
						entry.numerical_data = numeric_limits<double>::infinity();
						if(!token.empty()) {
							if(columns[column_number].is_string) entry.string_data.assign(token);					
							else entry.numerical_data = stod(token);
						}
						data_frame[columns[column_number].column_name].push_back(entry);
						column_number++;
						
					}
					n_rows++;
				}

			}
		}
		else return 1;
		cout <<"ROWS: "<<n_rows<<" COLUMNS: "<<n_columns<<"\n";
		return 0;

	}

	void print_column(string column_name) {

		vector<cell>::iterator it = data_frame[column_name].begin();
		while(it != data_frame[column_name].end()) {
			if(columns[column_index[column_name]].is_string) cout << it->string_data;
			else cout << it->numerical_data;
			cout<<"\n";
			it++;
		} 

	}
	void print_row(int start, int end) {
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
				if(columns[j].is_string) cout<<data_frame[columns[j].column_name][i].string_data<<",";
				else cout<<data_frame[columns[j].column_name][i].numerical_data<<",";
			}
			cout <<"\n";
		}
	}
	void get_column(string column_name, cell* cells) {
		int i;
		cout<<data_frame[column_name].size()<<"\n";
		for(i = 0;i<data_frame[column_name].size();i++){
			cells[i].string_data = data_frame[column_name][i].string_data;
			cells[i].numerical_data = data_frame[column_name][i].numerical_data;
		}


	}

	int get_ncolumns(){return n_columns;}
	int get_nrows(){return n_rows;}

};

int main() {

	DataFrame* df = new DataFrame;
	cell* origin_list = new cell[df->get_nrows()]; 
	df->get_column("origin",origin_list);
	
	for(int i =0;i < df->get_nrows();i++) {
		cout<<origin_list[i].string_data<<"\n";
	}
	
	return 0;

}
