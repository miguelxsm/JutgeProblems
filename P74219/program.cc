#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;
const Matrix I = {{1, 0}, {0, 1}};
const Matrix FIB = {{1, 1}, {1, 0}};
const Matrix FIB2 = {{1}, {0}};

//Pre: Matrix are regular
//Post: Returns the squared of the matrix
static Matrix squared_modul_matrix(const Matrix& A, const Matrix& B, int mod) {
    Matrix res(A.size(), vector<int>(B.size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            for (int k = 0; k < B.size(); ++k){
                res[i][j] += A[i][k] * B[k][j];
            }
            res[i][j] %= mod;
        }
    }
    return res;
}

Matrix modular_exp(const Matrix& mat, int k, int mod) {
    Matrix res(2,vector<int>(2));
    if (k == 0) return I;
    else {
        res = modular_exp(mat, k/2, mod);
        if (k % 2 == 0) return squared_modul_matrix(res, res, mod);
        else {
            res = squared_modul_matrix(res,res,mod);
            return squared_modul_matrix(res,mat,mod);
        }
    }
}

int fibonacci_n_mod(int n, int mod) {
    Matrix m(2, vector<int>(1));
    m = modular_exp(FIB, n, mod);
    m = squared_modul_matrix(m, FIB2, mod);
    return m[1][0];
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        cout << fibonacci_n_mod(n,m) << endl;
    }
}