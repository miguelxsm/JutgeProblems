#include <iostream>
using namespace std;
int main () {
    cout.setf(ios::fixed);
      cout.precision(1);

    int cantidad;
    cin >> cantidad;
    for (int i = 0; i < cantidad; ++i) {
        char tipo;
        double temperatura;
        cin >> tipo >> temperatura;
        if (tipo == 'C') {
            cout << "F " << 1.8*temperatura + 32.0 << endl;
        }
        else cout << "C " << (temperatura - 32.0)/1.8 << endl;
    }
}
