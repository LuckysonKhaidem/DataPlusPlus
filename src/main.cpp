#include <iostream>
#include "Series.h"
#include "MathUtil.h"
#include "SeriesOperations.h"
#include "DataFrame.h"

using namespace std;
using namespace mathutil;


int main() {
	DataFrame df("../dataset/AAPL1.csv",',');
	Series s;
  s = df["Close"][0] / df["Close"];
	cout << series_pow(series_sin(s),2) + series_pow(series_cos(s),2);
	return 0;
}
