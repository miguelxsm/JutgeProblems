#include <iostream>
using namespace std;
int main() {
    string palabra;
    bool cero = false;
    int cont = 0;
    bool encontrado = false;
    while (cin >> palabra and not cero) {
        if (palabra == "beginning") encontrado = true;
        if (encontrado) ++cont;
        if (palabra == "end" and encontrado) cero = true;
        else if (palabra == "end" and not encontrado) cero = true;
    }
    if (encontrado and cero) cout << cont - 2 << endl;
    else cout << "wrong sequence" << endl;
}
