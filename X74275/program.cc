#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int seq;
    int cont = 1;
    bool encontrado = false;
    while (cin >> seq and seq != -1 and not encontrado) { // mentre entra la dada seq y aquest valor no es -1
        if ((seq + n) % 10 == 0) {
            cout << seq;
            encontrado = true;
        }  // si el resto de seq + n entre 10 es 0 imprimir seq
        else ++cont;
    }
    if (encontrado) cout << ": " << cont << endl;
    else cout << "No existe" << endl;
}
