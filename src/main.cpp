#include <iostream>
#include "Series.h"
using namespace std;

int main() {
	double a[] = {4,1,2,3,45,7,8,223,4,6,7,123,446};
	double b[] = {6,7,3,4,5,56,3,123,43,5,6,7,1};
	int n1 = sizeof(a) / sizeof(a[0]);
	int n2 = sizeof(b) / sizeof(b[0]);
	cout<<n1<<" "<<n2<<"\n";
	Series r(a,n1);
	Series u(b,n2);
	
	Series result = r*u;
	result.print();
		

	return 0;
}
