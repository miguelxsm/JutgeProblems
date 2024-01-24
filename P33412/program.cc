#include <vector>
#include <iostream>
using namespace std;
bool i_resistant_search(double x, const vector<double> &v, int i, int j) {
	int m = (j + i) / 2;
	if (j < i) return false;
	if (v[m] == x) return true;
	else if (m > 0 and v[m - 1] == x) return true;
	else if (m < v.size() - 1 and v[m + 1] == x) return true;
	else if (v[m] > x) return i_resistant_search(x, v, i, m - 1);
	else return i_resistant_search(x, v, m + 1, j);
}

bool resistant_search(double x, const vector<double>& v) {
	return i_resistant_search(x, v, 0, int(v.size()-1));
}