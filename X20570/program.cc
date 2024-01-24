#include <iostream>
using namespace std;

int even_digits(int n) {
    if (n < 10 and n % 2 == 0) return n;
    else {
        if ((n % 10) % 2 == 0) {
            return n % 10 + even_digits(n / 10);
        }
        else return even_digits(n / 10);
    }
}

int main() {
    int x;
    while (cin >> x) cout << even_digits(x) << endl;
}
