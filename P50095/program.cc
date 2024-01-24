#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i) if (n%i == 0) return false;
    return true;
}

void next_prime(int& n) {
        n += 1;
        while (not is_prime(n)) n += 1;
}

int main() {
    int n;
    cin >> n;
    while (is_prime(n)) {
        next_prime(n);
        cout << n << endl;
        cin >> n;
    }
}