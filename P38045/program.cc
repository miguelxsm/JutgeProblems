#include <iostream>
#include <math.h>
using namespace std;

double raiz_cuadrada(int x) {
    double raiz = sqrt(x);
    return raiz;
}

int potencia(int x) {
    int potencia;
    potencia = x*x;
    return potencia;
}

int main() {

    cout.precision(6);
    cout.setf(ios::fixed);

    int n;
    while (cin >> n) {
        cout << potencia(n) << ' ' << raiz_cuadrada(n) << endl;
    }
}
