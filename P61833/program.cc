#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;
const Matrix I = {{1, 0}, {0, 1}};

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

static Matrix read_matrix(int n, int m) {
    Matrix mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    return mat;
}

static void print_matrix(const Matrix& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        bool primero = true;
        for (int j = 0; j < mat[0].size(); ++j) {
            if (!primero) cout << ' ';
            cout << mat[i][j];
            primero = false;
        }
        cout << endl;
    }
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

int main() {
    Matrix mat(2,vector<int>(2));
    int n;
    while (cin >> n) {
        mat[0][0] = n;
        cin >> mat[0][1];
        cin >> mat[1][0];
        cin >> mat[1][1];
        int k,mod;
        cin >> k >> mod;
        print_matrix(modular_exp(mat,k,mod));
        cout << "----------" << endl;
    }
}