#include <iostream>
#include <vector>
using namespace std;

// Pre: --
// Post: retorna la posición del último elemento en v con valor inferior a x,
//       retorna -1 si ese elemento no existe


int last_position_of(const vector<int>& v, double x) {
    // si empiezamos a leer el vector desde el final, pasará a ser una búsqueda y no un recorrido
    int n = v.size();
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] < x) return i;
    }
    return -1;

}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        double suma = 0.0;
        int pares = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (v[i] % 2 == 0) {
                suma += v[i];
                ++pares;
            }
        }
        double media = suma / pares;
        cout << last_position_of(v, media) << endl;
    }

}
