#include <iostream>
using namespace std;
bool es_prime (int n) {
    if (n < 2) return false;
    else {
        int i = 2;
        while (i*i <= n) {
            if (n % i == 0) return false;
            ++i;
        }
        return true;
    }
}

int suma_digits(int n) {
    if (n < 10) return n;
    else return n % 10 + suma_digits(n / 10);
}

bool is_perfect_prime(int n) {
    if (n < 10) return es_prime(n);
    else {
        if (es_prime(n)) {
            return is_perfect_prime(suma_digits(n));
        }
        return false;
    }
}

int main() {
    int n;
    while (cin >> n) {
        cout << is_perfect_prime(n) << endl;
    }
}