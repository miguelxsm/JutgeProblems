#include <iostream>
#include <vector>
using namespace std;

// Pre: p, pref están formadas por letras minúsculas
// Post: retorna true si pref es un prefijo de p, false en caso contrario
bool prefijo(const string& p, const string& pref) {
    for (int i = 0; i < pref.size(); ++i) {
        if (p[i] != pref[i]) return false;
    }
    return true;
}


void leer_vector(vector<string>& v) {
    for (int i = 0; i < v.size(); ++i) cin >> v[i];
}

int main() {
    int n;
    int linea = 1;
    while (cin >> n) {
        int prefijoo = 0;
        vector<string> v(n);
        leer_vector(v);
        for (int i = 0; i < v.size(); ++i) {
            if (prefijo(v[0], v[i])) ++prefijoo;
        }
        cout << "Linea " << linea << ": " << prefijoo << " - " << v[0] << endl;
        ++linea;
    }
}
