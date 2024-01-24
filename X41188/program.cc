#include <iostream>
using namespace std;

bool is_univariate(int n) {
    while (n / 10 != 0) {
        if (n % 10 != (n / 10) % 10) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int pos = 1;
    while (n != -1) {
        if (is_univariate(n)) {
            cout << pos << endl;
            return pos;
        }

        ++pos;
        cin >> n;
    }
    if (n == -1) cout << '0' << endl;
}
