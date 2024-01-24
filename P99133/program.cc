#include <iostream>
#include <vector>
using namespace std;

void girar_paraula(const string& palabra) {
    int n = palabra.size();
    for (int i = n - 1; i >= 0; --i) cout << palabra[i];
}

int main() {
    int n;
    cin >> n;
    vector<string> palabras(n);

    // entra valores
    for (int i = 0; i < n; ++i) {
        cin >> palabras[i];
    }

    //salida palabras de forma invertida;
    for (int i = n - 1; i >= 0; --i) {
        girar_paraula(palabras[i]);
        cout << endl;
    }

}