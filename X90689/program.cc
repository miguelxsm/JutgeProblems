#include <iostream>
using namespace std;

// Pre: a > 0 and b > 0
// Post: returns true when  pair (a, b) is three-sorted
//      returns false otherwise
bool is_three_sorted(int a, int b) {
    if (a % 3 == 0 and b % 3 == 0) return is_three_sorted(a / 3, b / 3);
    if (a % 3 == 0 and b % 3 != 0) return true;
    if (a % 3 != 0 and b % 3 != 0) return true;
    return false;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        if (is_three_sorted(n,m)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}
