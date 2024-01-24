#include <iostream>
#include <vector>
using namespace std;

int saber_pos (string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') return i;
    }
    return n;
}
int suma_de_todo(string s, int p) {
    int n = s.size();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'X') continue;
        else s[i] = s[i] - '0';
    }
    int suma = 0;
    for (int i = 0; i < n; ++i) {
            if (i == p) continue;
            else if (s[i] == 'X') suma += 10;
            else suma += (10 - i) * s[i];
        }


    return suma;
}

int main() {
    string s;
    while (cin >> s) {
        int pos = saber_pos(s);
        int suma = suma_de_todo(s,pos);
        int incognita;
        for (int i = 0; i < 11; ++i) {
            if ((suma + (10 - pos)*i) % 11 == 0) {
                if (i == 10) cout << 'X';
                else cout << i;
                cout << endl;
            }
        }

    }
}
