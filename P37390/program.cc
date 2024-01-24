#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

Matrix product(const Matrix& A, const Matrix& B) {
    int a = A.size();
    Matrix solucion(a, vector<int>(a));
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j) {
            for (int k = 0; k < a; ++k) {
                solucion[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return solucion;
}
