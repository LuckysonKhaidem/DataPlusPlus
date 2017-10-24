#include <iostream>
#include "DataFrame.h"
using namespace std;

int main() {
	int i = 0;
	DataFrame* df =  new DataFrame("AAPL1.csv",',');  
	cell* close_price = df->get_column("Open");
	for(;i< df->get_nrows();i++)
		cout<<close_price[i].numerical_data<<"\n";

	return 0;
}
