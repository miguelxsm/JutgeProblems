#include <iostream>
#include <vector>
using namespace std;

bool pangram(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) return false;
    }
    return true;
}
int numero(char c) {
        if (c >= 'a' and c <= 'z') return c - 'a';
        else return c - 'A';

}

int main() {

    char c;
    while (cin >> c) {
        vector<int> abc(26, 0);
        while (c != '.') {
            ++abc[numero(c)];
            cin >> c;
        }
        if (pangram(abc)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
