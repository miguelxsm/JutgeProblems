#include <iostream>
using namespace std;



int main() {
    int x;
    int n;
    int cont = 0;
    cin >> n;
    x = n;
    while (x != 0) {
        x /= 10;
        ++cont;
    }

    if (cont % 2 != 0 or n == 0) cout << "nada" << endl;
    else {
        int suma_derecha = 0;
        int suma_izquierda = 0;

        //parte de la derecha del número
        int cont2 = 0; //contador para contar cuantas veces se divide
        while (cont / 2 > cont2) {
            suma_derecha += n % 10;
            n /=10;
            ++cont2;
        }
        cont2 = 0;
        while (cont / 2 > cont2) {
            suma_izquierda += n % 10;
            n /=10;
            ++cont2;
    }

    if (suma_izquierda > suma_derecha) cout << suma_izquierda << " > " << suma_derecha << endl;
    else if (suma_izquierda < suma_derecha) cout << suma_izquierda << " < " << suma_derecha << endl;
    else cout << suma_izquierda << " = " << suma_derecha << endl;
}
}
