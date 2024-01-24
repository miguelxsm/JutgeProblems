#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    string nombre;
    int pastanagues;
    int caramels;
};

bool comparar(const Data& a, const Data& b) {
    if (a.caramels != b.caramels) return a.caramels > b.caramels;
    if (a.pastanagues != b.pastanagues) return a.pastanagues > b.pastanagues;
    if (a.nombre.size() != b.nombre.size()) return a.nombre.size() < b.nombre.size();
    else return a.nombre < b.nombre;
}

void leer_data(vector<Data>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) cin >> v[i].nombre >> v[i].caramels >> v[i].pastanagues;
}

void imprimir(vector<Data>& v) {
    for (int i = 0; i < v.size(); ++i) cout << v[i].nombre << endl;
}

int main() {
    int cantidad;
    cin >> cantidad;
    for (int o = 0; o < cantidad; ++o) {
        int numero_nombres;
        cin >> numero_nombres;
        vector<Data> v(numero_nombres);
            leer_data(v);
            sort(v.begin(), v.end(), comparar);
            imprimir(v);
            cout << endl;
    }
}
