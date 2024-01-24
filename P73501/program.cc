#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        bool primero = true;
        int cont = 0;
        while (cin >> m and m != 0) {
            int anterior;
            if (primero) {
                anterior = 2*m;
                primero = false;
            }
            if (anterior < m) ++cont;
            anterior = m;
        }
        cout << cont << endl;
    }
}
