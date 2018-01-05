#include "SeriesOperations.h"

Series operator+(double a, const Series& s) {
	if(s.getType() == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i =0 ; i < s.getSize(); i++) {
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a + s[i].data.number;
		}
		Series result_series(NUMBER, s.getSize(), "SUMMATION", result);
		return result_series;
	}
	else throw "Cannot add to a string series";


}
Series operator*(double a, const Series& s) {
	if(s.getType() == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i =0 ; i < s.getSize(); i++) {
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a * s[i].data.number;
		}
		Series result_series(NUMBER, s.getSize(), "PRODUCT", result);
		return result_series;
	}
	else throw "Cannot add to a string series";


}
Series operator/(double a, const Series& s) {
	if(s.getType() == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i =0 ; i < s.getSize(); i++) {
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a / s[i].data.number;
		}
		Series result_series(NUMBER, s.getSize(), "DIVISION", result);
		return result_series;
	}
	else throw "Cannot add to a string series";


}

Series operator-(double a, const Series& s) {
	if(s.getType() == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i =0 ; i < s.getSize(); i++) {
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a - s[i].data.number;
		}
		Series result_series(NUMBER, s.getSize(), "SUBTRACTION", result);
		return result_series;
	}
	else throw "Cannot add to a string series";

}



Series operator+(cell a, const Series& s) {
	if(s.getType() == NUMBER && a.type == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i = 0;i < s.getSize();i++)
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a.data.number + s[i].data.number;
		Series result_series(NUMBER, s.getSize(), "ADDITION", result);
		return result_series;
	}
	else throw "Operation not allowed on non numeric data";

}
Series operator-(cell a, const Series& s) {
	if(s.getType() == NUMBER && a.type == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i = 0;i < s.getSize();i++)
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a.data.number - s[i].data.number;
		Series result_series(NUMBER, s.getSize(), "ADDITION", result);
		return result_series;
	}
	else throw "Operation not allowed on non numeric data";
}
Series operator*(cell a, const Series& s) {
	if(s.getType() == NUMBER && a.type == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i = 0;i < s.getSize();i++)
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a.data.number * s[i].data.number;
		Series result_series(NUMBER, s.getSize(), "ADDITION", result);
		return result_series;
	}
	else throw "Operation not allowed on non numeric data";
}

Series operator/(cell a, const Series& s) {
	if(s.getType() == NUMBER && a.type == NUMBER) {
		vector<cell> result(s.getSize());
		for(int i = 0;i < s.getSize();i++)
			if(s[i].type == MISSING)
				result[i].type = MISSING;
			else
				result[i].data.number = a.data.number / s[i].data.number;
		Series result_series(NUMBER, s.getSize(), "ADDITION", result);
		return result_series;
	}
	else throw "Operation not allowed on non numeric data";
}

vector<bool> operator&& (vector<bool> m1, vector<bool> m2) {
	vector<bool> result(m1.size());
	for(int i =0 ; i< m1.size();i++) result[i] = m1[i] && m2[i];
	return result;
}
vector<bool> operator|| (vector<bool> m1, vector<bool> m2) {
	vector<bool> result(m1.size());
	for(int i =0 ; i< m1.size();i++) result[i] = m1[i] || m2[i];
	return result;
}
