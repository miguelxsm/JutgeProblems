#include <iostream>
#include <vector>
using namespace std;
using Tablero = vector<vector<char>>;

void escribir_tablero(const Tablero& t) {
    for (int i = 0; i < t.size(); ++i) {
        for (int j =0; j < t.size(); ++j) {
            cout << t[i][j];
        }
        cout << endl;
    }
}

bool safe_pos(int i, int j, vector<bool>& diagonal1, vector<bool>& diagonal2, vector<bool> columna) {
    return !columna[j] && !diagonal1[j-i+columna.size()] && !diagonal2[i+j];
}

void nreinas(Tablero& t, int k, int i, int j, vector<bool>& diagonal1, vector<bool>& diagonal2, vector<bool>& columna, int n, int& n_sols) {
    if (n == 0) {
        escribir_tablero(t);
        cout << endl;
    }
    else {
        while (j < k) {
            if (safe_pos(i,j,diagonal1,diagonal2,columna)) {

                columna[j] = diagonal1[j-i+k] = diagonal2[i+j] = true;
                t[i][j] = 'Q';
                nreinas(t, k, i+1,0,diagonal1,diagonal2,columna,n-1,n_sols);
                t[i][j] = '.';
                columna[j] = diagonal1[j-i+k] = diagonal2[i+j] = false;
            }
            ++j;
        }
    }
}


int main() {
    int n; cin >> n;
    vector<bool> diagonal1(2*n - 1,false);
    vector<bool> diagonal2(2*n - 1,false);
    vector<bool> columnas(n,false);
    int n_sols = 0;
    Tablero t(n,vector<char>(n,'.'));
    nreinas(t, n,0,0,diagonal1,diagonal2,columnas,n,n_sols);
}