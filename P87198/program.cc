#include <iostream>
using namespace std;
int main() {
    int n;
while (cin >> n) {
    int espacios = n - 1;
    int x = n;
    //parte de arriba
    for (int i = 0; i < n - 1; ++i) {
        // espacios
        for (int j = 0; j < espacios; ++j) cout << ' ';
        for (int j = 0; j < x; ++j) cout << 'X';
        cout << endl;
        --espacios;
        x += 2;
    }

    // parte del medio
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3*n - 2; ++j) cout << 'X';
        cout << endl;
    }
    //parte de abajo

    for (int i = 0; i <= n - 1; ++i) {
        for (int j = espacios; j << 0; --j) cout << ' ';
        for (int j = x; j != 0; --j) cout << 'X';
        cout << endl;
        ++espacios;
        x -= 2;
    }
    cout << endl;
}
}
