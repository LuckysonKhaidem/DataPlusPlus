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
  s = df["Close"] / df["Open"];
	cout << s;
	return 0;
}
