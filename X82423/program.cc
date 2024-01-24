#include <iostream>
using namespace std;

int main() {
    int cantidad;
    cin >> cantidad;
    for (int i = 0; i < cantidad; ++i) {
        int n;
        cin >> n;
        int pos_cadena = 0;
        int pos = 1;
        int longitud_cadena = 0;
        int anterior = n;
        int longitud_actual = 0;
        while (n != -1) {

            if (anterior == n) {
                ++longitud_actual;
            }
            else longitud_actual = 1;

            if (longitud_cadena < longitud_actual) {
                longitud_cadena = longitud_actual;
                pos_cadena = pos;
            }

            ++pos;
            anterior = n;
            cin >> n;
        }
        cout << pos_cadena - longitud_cadena + 1 << ' ' << longitud_cadena << endl;

    }
}
