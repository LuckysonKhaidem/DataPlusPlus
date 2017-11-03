#include "Series.h"
using namespace std;


Series::Series() {}

Series::Series(int type, int size, string series_name, vector<cell>& cells) {
	this->type = type;
	this->size = size;
	this->series_name = series_name;
	this->cells = cells;
}

Series::Series(int type, int size, string series_name, cell* cells) {
	this->type = type;
	this->size = size;
	this->series_name = series_name;

	for(int i = 0; i < size; i++)
		this->cells.push_back(cells[i]);
}
Series::Series(double* arr, int size) {
	this->type = NUMBER;
	this->size = size;
	this->series_name = "NUMBER SERIES";
	for(int i =0 ; i < this->size;i++){
		cell c;
		c.type = NUMBER;
		c.data.number = arr[i];
		this->cells.push_back(c);
	}
}


Series::Series(char** arr, int size) {
	this->type = STRING;
	this->size = size;
	this->series_name = "STRING SERIES";
	for(int i =0 ; i < this->size;i++){
		cell c;
		c.type = STRING;
		c.data.text = (char*)malloc(sizeof(arr[i]) + 1);
		strcpy(c.data.text,arr[i]);
		this->cells.push_back(c);
	}
}


Series::~Series(){

}

cell Series::operator[](int index) const {
	return this->cells[index];
}

int Series::getType() const {
	return this->type;
}
int Series::getSize() const{
	return this->size;
}
string Series::getName() const {
	return this->series_name;
}

Series Series::operator+(Series b) {
	if(this->size == b.getSize() && this->type == NUMBER && b.getType() == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING || b[i].type == MISSING)
				result[i].type = MISSING;
			else{
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number + b[i].data.number;
			}
		}
		Series result_series(NUMBER, this->size, "SUMMATION", result);
		return result_series;
	}
	else throw "INVALID ARGUMENT";
}

Series Series::operator-(Series b) {
	if(this->size == b.getSize() && this->type == NUMBER && b.getType() == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING || b[i].type == MISSING)
				result[i].type = MISSING;
			else{
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number - b[i].data.number;
			}
		}
		Series result_series(NUMBER, this->size, "SUBTRACTION", result);
		return result_series;
	}
	else throw "INVALID ARGUMENT";
}

Series Series::operator*(Series b) {
	if(this->size == b.getSize() && this->type == NUMBER && b.getType() == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING || b[i].type == MISSING)
				result[i].type = MISSING;
			else {
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number * b[i].data.number;
			}

		}
		Series result_series(NUMBER, this->size, "PRODUCT", result);
		return result_series;
	}
	else throw "INVALID ARGUMENT";
}

Series Series::operator/(Series b) {
	if(this->size == b.getSize() && this->type == NUMBER && b.getType() == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING || b[i].type == MISSING)
				result[i].type = MISSING;
			else{
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number / b[i].data.number;
			}
		}
		Series result_series(NUMBER, this->size, "DIVISION", result);
		return result_series;

	}
	else throw "INVALID ARGUMENT";
}

double Series::mean() {
	if(this->type == STRING) throw "Cannot find mean of string series";
	double sum = 0;
	if(!calculated["mean"]){
		sum = this->sum();
		statistics["mean"] = sum / getSize();
		calculated["mean"] = true;
	}
	return statistics["mean"];
}
double Series::sum() {
	if(this->type == STRING) throw "Cannot find sum of string series";
	double sum = 0;
	if(!calculated["sum"]){
		for(int i=0;i<getSize();i++)
			sum += this->cells[i].data.number;
		statistics["sum"] = sum;
		calculated["sum"] = true;
	}
	return statistics["sum"];

}

double Series::max() {
	if(this->type == STRING) throw "Cannot find max of string series";
	if(calculated["max"]) return statistics["max"];
	double max = DBL_MIN;
	for(int i = 0 ; i < this->size ;i++) {
		if(cells[i].type == NUMBER && cells[i].data.number > max) {
			max = cells[i].data.number;
		}
	}
	statistics["max"] = max;
	return max;
}

double Series::min() {
	if(this->type == STRING) throw "Cannot find min of string series";
	if(calculated["min"]) return statistics["min"];
	double min = DBL_MAX;
	for(int i = 0 ; i < this->size ;i++) {
		if(cells[i].type == NUMBER && cells[i].data.number < min) {
			min = cells[i].data.number;
		}
	}
	statistics["min"] = min;
	return min;
}


double Series::std() {
	if(this->type == STRING) throw "Cannot find standard deviation of string series";
	double std = 0;
	if(!calculated["std"]) {
		double mean = this->mean();
		for(int i =0; i < this->getSize(); i++) {
			std += (mean - this->cells[i].data.number)*(mean - this->cells[i].data.number);
		}
		std = std / getSize();
		std = sqrt(std);
		calculated["std"] = true;
		statistics["std"] = std;
	}
	return statistics["std"];
}

Series Series::operator+(double a) {
	if(this->type == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING)
				result[i].type = MISSING;
			else{
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number + a;
			}
		}
		Series result_series(NUMBER, this->size, "SUMMATION", result);
		return result_series;
	}
	else throw "Cannot add to a string series";
}


Series Series::operator-(double a) {
	if(this->type == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING)
				result[i].type = MISSING;
			else
			{
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number - a;
			}
		}
		Series result_series(NUMBER, this->size, "SUBTRACTION", result);
		return result_series;
	}
	else throw "Cannot subtract from a string series";
}

Series Series::operator*(double a) {
	if(this->type == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING)
				result[i].type = MISSING;
			else{
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number * a;
			}
		}
		Series result_series(NUMBER, this->size, "PRODUCT", result);
		return result_series;
	}
	else throw "Cannot multiply a string series";
}

Series Series::operator/(double a) {
	if(this->type == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING)
				result[i].type = MISSING;
			else{
				result[i].type = NUMBER;
				result[i].data.number = this->cells[i].data.number / a;
			}
		}
		Series result_series(NUMBER, this->size, "DIVISION", result);
		return result_series;
	}
	else throw "Cannot divide a string series";
}
Series Series::operator-() {
	if(this->type == NUMBER) {
		vector<cell> result(this->size);
		for(int i =0 ; i < this->size; i++) {
			if(this->cells[i].type == MISSING)
				result[i].type = MISSING;
			else{
				result[i].type = NUMBER;
				result[i].data.number = -this->cells[i].data.number;
			}
		}
		Series result_series(NUMBER, this->size, "NEGATION", result);
		return result_series;
	}
	else throw "Cannot negate a string series";

}


vector<bool> Series::operator>(double num) {
	if(this->type == NUMBER) {
		vector<bool> mask(this->size);
		for(int i = 0; i < this->size ;i++) {
			if(this->cells[i].type == MISSING)
				mask[i] = false;
			else if(this->cells[i].data.number > num)
				mask[i] = true;
			else
				mask[i] = false;
		}
		return mask;
	}else throw "Cannon perform operation on a non number series";
}

vector<bool> Series::operator<(double num) {
	if(this->type == NUMBER) {
		vector<bool> mask(this->size);
		for(int i = 0; i < this->size ;i++) {
			if(this->cells[i].type == MISSING)
				mask[i] = false;
			else if(this->cells[i].data.number < num)
				mask[i] = true;
			else
				mask[i] = false;
		}
		return mask;
	}else throw "Cannon perform operation on a non number series";
}

vector<bool> Series::operator>=(double num) {
	if(this->type == NUMBER) {
		vector<bool> mask(this->size);
		for(int i = 0; i < this->size ;i++) {
			if(this->cells[i].type == MISSING)
				mask[i] = false;
			else if(this->cells[i].data.number >= num)
				mask[i] = true;
			else
				mask[i] = false;
		}
		return mask;
	}else throw "Cannon perform operation on a non number series";
}

vector<bool> Series::operator<=(double num) {
	if(this->type == NUMBER) {
		vector<bool> mask(this->size);
		for(int i = 0; i < this->size ;i++) {
			if(this->cells[i].type == MISSING)
				mask[i] = false;
			else if(this->cells[i].data.number <= num)
				mask[i] = true;
			else
				mask[i] = false;
		}
		return mask;
	}else throw "Cannon perform operation on a non number series";
}
vector<bool> Series::operator==(double num) {
	if(this->type == NUMBER) {
		vector<bool> mask(this->size);
		for(int i = 0; i < this->size ;i++) {
			if(this->cells[i].type == MISSING)
				mask[i] = false;
			else if(this->cells[i].data.number == num)
				mask[i] = true;
			else
				mask[i] = false;
		}
		return mask;
	}else throw "Cannon perform operation on a non number series";
}


Series Series::operator[](vector<bool> mask) {
	vector<cell> cells;
	for(int i =0 ; i<this->size ;i++) {
		if(mask[i] == true){
			cell c;
			c.type = this->cells[i].type;
			if(c.type == NUMBER) c.data.number = this->cells[i].data.number;
			else{
				c.data.text = (char*)malloc(strlen(this->cells[i].data.text) + 1);
				strcpy(c.data.text, this->cells[i].data.text);
			}
			cells.push_back(c);
		}
	}
	Series result_series(this->type,cells.size(), "MASKED",cells);
	return result_series;
}

ostream& operator<<(ostream& os, const Series& s) {

	for(int i =0 ; i < s.getSize();i++){
		if(s[i].type == NUMBER) os<<s[i].data.number;
		else cout<<s[i].data.text;
		os<<"\n";
	}

	return os;

}
