#include <iostream>
#include <vector>
using namespace std;

string Hamming(string s, vector<string> v, int diferencia) {
    int n = v.size();
    int tamaño = s.size();
    for (int i = 0; i < n; ++i) {
        int diferencia2 = diferencia;
        string string2 = v[i];
        int tamaño2 = string2.size();
        if (tamaño == tamaño2) {
            for (int j = 0; j < tamaño; ++j) {
                if (s[j] != string2[j]) --diferencia2;
            }
            if (diferencia2 >= 0) return v[i];
        }
    }
    return "--";
}
int main() {
    int diferencia;
    cin >> diferencia;
    int n;
    cin >> n;
    vector <string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    string s;
    cin >> s;
    while (s != "STOP") {
        cout << s << ": " << Hamming(s, v, diferencia) << endl;
        cin >> s;
    }
}
