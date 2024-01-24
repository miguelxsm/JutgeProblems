#include <iostream>
using namespace std;

void barrejats(int n, int m) {
    if (n <= 1 and m <= 1) cout << n << m;
    else {
        barrejats(n/2, m/2);
        cout << n%2 << m%2;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        barrejats(n, m);
        cout << endl;

    }

}
