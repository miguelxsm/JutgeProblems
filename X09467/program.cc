#include <iostream>
#include <vector>
using namespace std;

vector<bool> pos_rampas(const vector <int>& V) {
    int n = V.size();
    vector<bool> hay_rampa(n);
    for (int i = 0; i < n - 2; ++i) {
        if ((V[i] > V[i + 1] and V[i + 1] > V[i + 2]) or (V[i] < V[i + 1] and V[i + 1] < V[i + 2])) {
            hay_rampa[i] = true;
        }
        else hay_rampa[i] = false;
    }
    return hay_rampa;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        //se crea un vector boleano con las posiciones donde hay rampas.
        cout << "posiciones con rampa:";
        vector<bool> hay_rampa = pos_rampas(v);
        //hay_rampa es un vector a lo (1,0,0,1,1,1)

        for (int i = 0; i < n; ++i) {
            if (hay_rampa[i]) cout << ' ' << i;
        }
        cout << endl;

        //posiciones conflictivas
        cout << "potencialmente conflictivas: ";
        int conflict = 0;
        //usaremos el vector boleano hay_rampa para contar cuantas posiciones conflictivas hay
        for (int i = 0; i < n - 2; ++i) {
            if (hay_rampa[i]) {
                if (hay_rampa[i + 1]) ++conflict;
                if (hay_rampa[i + 2]) ++conflict;
            }
        }
        cout << conflict << endl;
        cout << "---" << endl;
    }
}
