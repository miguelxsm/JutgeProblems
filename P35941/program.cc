#include <iostream>
using namespace std;

int posicion_abecedario(string abecedario, char c) {
    for (int i = 0; i < 26; ++i) {
        if (abecedario[i] == c) return i;
    }
    return c;
}

int main() {
    string abecedario;
    while (cin >> abecedario) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string c;
            cin >> c;
            int m = c.size();
            for (int i = 0; i < m; ++i) {
                if (c[i] == '_') cout << ' ';
                else cout << char('a' + posicion_abecedario(abecedario, c[i]));
            }
            cout << endl;
            }
            cout << endl;
        }
    }
