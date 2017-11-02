#include <iostream>
#include "Series.h"
#include "MathUtil.h"
#include "SeriesOperations.h"
#include "DataFrame.h"

using namespace std;
using namespace mathutil;


int main() {
	DataFrame df("../dataset/AAPL1.csv",',');
	cout<<df["Close"][series_pow(df["Close"] / 100.0,2)>=2.0];

	return 0;
}
