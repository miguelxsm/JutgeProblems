#include <iostream>
using namespace std;
int main() {
    int n;
    int sumador = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char p;
            cin >> p;
            if ((i == j) || i + j + 1 == n) sumador += p -'0';
        }
    }


    cout << sumador << endl;
}
