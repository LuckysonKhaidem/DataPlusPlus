#include "MathUtil.h"

Series mathutil::series_sin(const Series& s) {
	if(s.getType() == STRING) throw "Cannot find cosine of string series";
	else{
		std::vector<cell> result(s.getSize());
		for(int i =0 ;i < s.getSize();i++) {
			if(s[i].type == MISSING) result[i].type = MISSING;
			else{
				result[i].type = NUMBER; 
				result[i].data.number = sin(s[i].data.number);
			} 
		}
		Series result_series(NUMBER, s.getSize(), "SINE", result);
		return result_series;
	}

} 

Series mathutil::series_cos(const Series& s) {
	if(s.getType() == STRING) throw "Cannot find cosine of string series";
	else{
		std::vector<cell> result(s.getSize());
		for(int i =0 ;i < s.getSize();i++) {
			if(s[i].type == MISSING) result[i].type = MISSING;
			else{
				result[i].type = NUMBER; 
				result[i].data.number = cos(s[i].data.number);
			} 
		}
		Series result_series(NUMBER, s.getSize(), "COSINE", result);
		return result_series;
	}

} 
Series mathutil::series_tan(const Series& s) {
	if(s.getType() == STRING) throw "Cannot find cosine of string series";
	else{
		std::vector<cell> result(s.getSize());
		for(int i =0 ;i < s.getSize();i++) {
			if(s[i].type == MISSING) result[i].type = MISSING;
			else{
				result[i].type = NUMBER; 
				result[i].data.number = tan(s[i].data.number);
			} 
		}
		Series result_series(NUMBER, s.getSize(), "TANGENT", result);
		return result_series;
	}

} 

Series mathutil::series_exp(const Series& s) {
	if(s.getType() == STRING) throw "Cannot find exp of string series";
	else{
		std::vector<cell> result(s.getSize());
		for(int i =0 ;i < s.getSize();i++) {
			if(s[i].type == MISSING) result[i].type = MISSING;
			else{
				result[i].type = NUMBER; 
				result[i].data.number = exp(s[i].data.number);
			} 
		}
		Series result_series(NUMBER, s.getSize(), "EXP", result);
		return result_series;
	}

} 

Series mathutil::series_log(const Series& s) {
	if(s.getType() == STRING) throw "Cannot find exp of string series";
	else{
		std::vector<cell> result(s.getSize());
		for(int i =0 ;i < s.getSize();i++) {
			if(s[i].type == MISSING) result[i].type = MISSING;
			else{
				result[i].type = NUMBER; 
				result[i].data.number = log(s[i].data.number);
			} 
		}
		Series result_series(NUMBER, s.getSize(), "LOG", result);
		return result_series;
	}

} 

Series mathutil::series_log10(const Series& s) {
	if(s.getType() == STRING) throw "Cannot find log10 of string series";
	else{
		std::vector<cell> result(s.getSize());
		for(int i =0 ;i < s.getSize();i++) {
			if(s[i].type == MISSING) result[i].type = MISSING;
			else{
				result[i].type = NUMBER; 
				result[i].data.number = log10(s[i].data.number);
			} 
		}
		Series result_series(NUMBER, s.getSize(), "LOG10", result);
		return result_series;
	}

} 

Series mathutil::series_pow(const Series& s, int power) {
	if(s.getType() == STRING) throw "Cannot find pow of string series";
	else{
		std::vector<cell> result(s.getSize());
		for(int i =0 ;i < s.getSize();i++) {
			if(s[i].type == MISSING) result[i].type = MISSING;
			else{
				result[i].type = NUMBER; 
				result[i].data.number = pow(s[i].data.number,power);
			} 
		}
		Series result_series(NUMBER, s.getSize(), "pow", result);
		return result_series;
	}

} 