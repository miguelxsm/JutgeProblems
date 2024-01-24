#include <iostream>
using namespace std;
int main() {
    int n;

    cin >> n;
    //parte de arriba

    for (int i = 0; i < n - 1; ++i) {
                // espacios
        for (int j = 1; j < n - i; ++j) cout << ' ';
        // *
        for (int j = 0; j < 2*i + 1; ++j) cout << '*';
        cout << endl;
    }
    // parte del medio
    for (int i = 0; i < 2*n - 1; ++i) cout << '*';
    cout << endl;

    for (int i = n - 1; i != 0; --i) {
        for (int j = 0; j < n - i; ++j) cout << ' ';
        for (int j = 0; j < 2*i - 1; ++j) cout << '*';
        cout << endl;
    }
    }




    //espacios
