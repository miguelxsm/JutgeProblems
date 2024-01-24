#include <iostream>
using namespace std;
int main() {

    char c;
    bool encontrado = false;
    while (cin >> c and not encontrado) {
        if (c == 'a') encontrado = true;
    }
    if (encontrado) cout << "si" << endl;
    else cout << "no" << endl;
}
