#include <iostream>
#include <vector>
using namespace std;
using Tablero = vector<vector<char>>;

bool safe_pos(int i, int j, vector<bool>& diagonal1, vector<bool>& diagonal2, vector<bool>& columna) {
    return !columna[j] && !diagonal1[j-i+columna.size()] && !diagonal2[i+j];
}

void nreinas(int k, int i, int j, vector<bool>& diagonal1, vector<bool>& diagonal2, vector<bool>& columna, int n, int& n_sols) {
    if (n == 0) {
        ++n_sols;
    }
    else {
        while (j < k) {
            if (safe_pos(i,j,diagonal1,diagonal2,columna)) {

                columna[j] = diagonal1[j-i+k] = diagonal2[i+j] = true;

                nreinas(k, i+1,0,diagonal1,diagonal2,columna,n-1,n_sols);

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
    nreinas(n,0,0,diagonal1,diagonal2,columnas,n,n_sols);
    cout << n_sols << endl;
}