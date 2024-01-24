#include <iostream>
using namespace std;
bool is_palindromic(int n) {
        int x = n;
        int n_reverse = 0;
        while (x != 0) {
            n_reverse = n_reverse * 10 + x % 10;
            x /= 10;
        }
        return n_reverse == n;
}

int main() {
    int n;
    cin >> n;
    cout << is_palindromic(n) << endl;
}
