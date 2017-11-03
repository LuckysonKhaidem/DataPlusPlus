#include <iostream>
#include "Series.h"
#include "MathUtil.h"
#include "SeriesOperations.h"
#include "DataFrame.h"

using namespace std;
using namespace mathutil;


int main() {
	DataFrame df("../dataset/AAPL1.csv",',');
	cout<<df["Close"].mean();
	cout<<df["Close"];
	return 0;
}
