#include <iostream>
using namespace std;
char encoded(char c, int k) {
    if (c >= 'a' and c <= 'z') {
        int desfase = 32 - k%26;
        if (c - desfase <= 'Z') return char(c - desfase);
        else return char('A' - 1 + (c - desfase) % 'Z');

    }
    else if (c == '_') return ' ';
    else return c;
}
int main() {
    int k;
    char c;
    while (cin >> k) {
        cin >> c;
        while (c != '.') {
        cout << encoded(c,k);
            cin >> c;
        }
        cout << endl;
    }
    }
