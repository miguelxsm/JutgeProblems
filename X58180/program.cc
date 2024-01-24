#include <iostream>
using namespace std;

bool is_subchain(int n, int m) {
    if (n == 0) return true;
    else {
        if (n != 0 and m == 0) return false;
        if (n % 10 == m % 10) return is_subchain(n / 10, m / 10);
        else return is_subchain(n, m / 10);
    }
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        if (is_subchain(n,m)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}
