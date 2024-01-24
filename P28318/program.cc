#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriz;

void escribe(Matriz& m, string s) {
    if (s == "row") {
        int p;
        cin >> p;
        cout << ' ' << p << ':';
        --p;
        int n = m[0].size();
        for (int i = 0; i < n; ++i) cout << ' ' << m[p][i];
    }

    if (s == "column") {
        int p;
        cin >> p;
        cout << ' ' << p << ':';
        --p;    
        int n = m.size();
        for (int i = 0; i < n; ++i) cout << ' ' << m[i][p];
    }

    if (s == "element") {
        int p,t;
        cin >> p >> t;
        cout << ' ' << p << ' ' << t << ':';
        --p;
        --t;
        cout << ' ' << m[p][t];
    }
}

void leer_matriz(Matriz& m) {
    int f = m.size();
    int c = m[0].size();
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) cin >> m[i][j];
    }
}

int main() {
    int filas, columnas;
    cin >> filas >> columnas;
    Matriz mat(filas, Fila(columnas));
    leer_matriz(mat);
    string s;
    while (cin >> s) {
        cout << s;
        escribe(mat, s);
        cout << endl;

    }
}
