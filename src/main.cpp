#include <iostream>
#include "Series.h"
#include "MathUtil.h"
#include "SeriesOperations.h"

using namespace std;
using namespace mathutil;


int main() {

	double a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	double b[] = {6,7,3,4,5,56,3,123,43,5,6,7,1};
	int n1 = sizeof(a) / sizeof(a[0]);
	int n2 = sizeof(b) / sizeof(b[0]);
	
	Series r(a,n1);
	Series u(b,n2);

	cout<<r[((r>=2) && (r<=10)) || (r == 20)];
		

	return 0;
}
