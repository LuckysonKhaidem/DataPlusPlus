#include <iostream>
#include "Series.h"
using namespace std;

int main() {
	double a[] = {4,1,2,3,45,7,8,223,4,6,7,123,446};
	int n = sizeof(a) / sizeof(a[0]);
	Series r(a,n);
	

	return 0;
}
