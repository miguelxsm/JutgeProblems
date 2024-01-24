#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Bosque;

void leer_bosque(Bosque& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) cin >> v[i][j];
    }
}

void escribir_bosque(const Bosque& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) cout << v[i][j];
        cout << endl;
    }
}

void propagacion(Bosque& v, int  i, int j) {

    v[i][j] = '.';
    //1 casilla a la izquierda
    if (j > 0 and v[i][j - 1] == 'A') {
        propagacion(v, i, j - 1);
    }
    // 1 casilla a la derecha
    if (j < v[0].size() - 1 and v[i][j + 1] == 'A'){
        propagacion(v, i, j + 1);
    }
    // 1 casilla abajo
    if (i < v.size() - 1 and v[i + 1][j] == 'A') {
        propagacion(v, i + 1, j);
    }
    // 1 casilla arriba
    if (i > 0 and v[i - 1][j] == 'A') {
        propagacion(v, i - 1, j);
    }
}



int main() {
    int n, m;
    while (cin >> n >> m) {
        Bosque v(n, vector<char>(m));
        leer_bosque(v);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'F') {
                    propagacion(v, i, j);

                }
            }
        }
        escribir_bosque(v);
        cout << endl;
    }
}
