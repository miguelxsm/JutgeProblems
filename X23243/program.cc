#include <iostream>
using namespace std;

int suma_digitos(int n) {
    if (n < 10) return n;
    else return n % 10 + (suma_digitos(n / 10));
}

int main() {
    int n1;
    int anterior;
    int cont = 0;
    bool primero = true;
    while (cin >> n1) {
        if (not primero and anterior % suma_digitos(n1) == 0) ++cont;
        anterior = n1;
        if (primero) primero = false;
    }
    cout << cont << endl;
}
