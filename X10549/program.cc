#include <iostream>
using namespace std;
// Pre: x > 0
// Post: returns the value of x without 0 digits
int remove_zeros(int x) {
    if (x < 10 and x > 0) return x;
    else {
        if (x % 10 == 0) return remove_zeros(x / 10);
        else return x % 10 + 10*remove_zeros(x / 10);
    }
}

int main() {
    int n;
    while (cin >> n) {
        cout << remove_zeros(n) << endl;
    }
}
