#include <iostream>
using namespace std;
int main() {
    int n;
    int seq;
    int cont = 0;
    cin >> n;
    bool encontrado = false;
    while (cin >> seq && not encontrado) {
        if (cont == n - 1) {
            cout << "At the position " << n << " there is a(n) " << seq << '.' << endl;
            encontrado = true;
        }
        ++cont;
    }
    if (not encontrado) cout << "Incorrect position." << endl;
}
