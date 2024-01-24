#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matriz;

bool arriba_derecha(const Matriz& tabla, int x, int y) {
    int anterior = tabla[x][y];
    --x;
    ++y;
    while (y < tabla[0].size() and x >= 0) {
        if (tabla[x][y] <= anterior) return false;
        anterior = tabla[x][y];
        --x;
        ++y;
    }
    return true;
}

bool arriba_izquierda(const Matriz& tabla, int x, int y) {
    int anterior = tabla[x][y];
    --x;
    --y;
    while (y >= 0 and x >= 0) {
        if (tabla[x][y] <= anterior) return false;
        anterior = tabla[x][y];
        --x;
        --y;
    }
    return true;
}

bool abajo_izquierda(const Matriz& tabla, int x, int y) {
    int anterior = tabla[x][y];
    ++x;
    --y;
    while (y >= 0 and x < tabla.size()) {
        if (tabla[x][y] <= anterior) return false;
        anterior = tabla[x][y];
        ++x;
        --y;
    }
    return true;
}

bool abajo_derecha(const Matriz& tabla, int x, int y) {
    int anterior = tabla[x][y];
    ++x;
    ++y;
    while (y < tabla[0].size() and x < tabla.size()) {
        if (tabla[x][y] <= anterior) return false;
        anterior = tabla[x][y];
        ++x;
        ++y;
    }
    return true;
}


int main() {
    int filas, columnas;
    while (cin >> filas >> columnas) {

            //declaramos y leemos
            Matriz tabla(filas, vector<int> (columnas));
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) cin >> tabla[i][j];
            }

            int x, y;
            cin >> x >> y;
            if (arriba_derecha(tabla,x,y) and abajo_derecha(tabla,x,y) and arriba_izquierda(tabla,x,y) and abajo_izquierda(tabla,x,y)) cout << "yes";
            else cout << "no";
            cout << endl;
    }

}
