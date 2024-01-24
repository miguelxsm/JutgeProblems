#include <iostream>
using namespace std;
int main() {
    int cantidad;
    cin >> cantidad;
    for (int i = 0; i < cantidad; ++i) {
        int puntos_perdidos = 0;
        string s1, s2;
        cin >> s1 >> s2;
        while (s2 != "end") {
            if (s1 != s2 and s2 != "multicolor") ++puntos_perdidos;
            if (s2 != "multicolor") s1 = s2;
            cin >> s2;
        }
        cout << puntos_perdidos << endl;
    }
}
