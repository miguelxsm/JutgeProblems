#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    while (a != -1) {
        char op;
        int b;
        cin >> op >> b;
        if (op == '+') cout << a + b;
        else if (op == '-') cout << a - b;
        else cout << a*b;
        cout << endl;
        cin >> a;
    }
}
