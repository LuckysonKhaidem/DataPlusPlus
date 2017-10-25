#include <iostream>
#include "DataFrame.h"
using namespace std;

int main() {
	cout<<"ASDFGH\n";
	int i = 0;
	DataFrame* df =  new DataFrame("../dataset/AAPL1.csv",',');  
	cell* close_price = df->get_column("Open");
	for(;i< df->get_nrows();i++)
		cout<<close_price[i].numerical_data<<"\n";

	return 0;
}
