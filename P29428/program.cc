#include <iostream>
#include <vector>
using namespace std;

bool palabra_inscrita(string mayor, string menor) {
    bool terminado = false;
    int j = 0;
    int tamaño = menor.size();
    int pos = 0;
    for (int i = 0; i < mayor.size(); ++i) {
        if (menor[j] == mayor[i]) {
            ++j;
            if (j == tamaño) terminado = true;
        }
        else {
            j = 0;
            ++pos;
            i = pos - 1;
        }
    }
    return terminado;
}

void que_hay_dentro(const vector<string>& s) {
    int tamaño = s.size();
    for (int i = 0; i < tamaño; ++i) {
        cout << s[i] << ':';
        for (int j = 0; j < tamaño; ++j) {
            if (s[i].size() >= s[j].size()) {
                if (palabra_inscrita(s[i], s[j])) cout << ' ' << s[j];
        }
    }
    cout << endl;
}
}





int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    que_hay_dentro(s);
}
