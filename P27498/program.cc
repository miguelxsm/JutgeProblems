#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

void transpose(Matrix& m) {
    int n = m[0].size();
    Matrix solucion(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) solucion[i][j] = m[j][i];
    }
    m = solucion;
}
