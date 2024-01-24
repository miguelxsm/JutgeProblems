#include <iostream>
using namespace std;
int main() {

    int n;
    int cont = 0;
    bool encontrado = false;
    while (cin >> n and not encontrado) {
        if (n % 2 == 0) encontrado = true;
        cont++;
    }
    cout << cont << endl;
}
