#include <iostream>
using namespace std;
int main() {

    int anterior, actual, siguiente, pica;
    bool encontrado = false;
    pica = 3143;

    cin >> anterior >> actual >> siguiente;
    while (siguiente != 0 and not encontrado) {
        if (actual > pica and actual > anterior and actual > siguiente) encontrado = true;
        anterior = actual;
        actual = siguiente;
        cin >> siguiente;
        }

    if (encontrado) cout << "YES";
    else cout << "NO";
    cout << endl;
}
