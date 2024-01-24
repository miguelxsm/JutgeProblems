#include <iostream>
#include <vector>
using namespace std;
const int LONG_ALFABET = 'z' - 'a' + 1;

char lletra_mes_frequent(const string& s) {
        vector <int> lmf(LONG_ALFABET, 0);
        int tams = s.size();
        for (int i = 0; i < tams; ++i) {
                ++lmf[s[i]-'a'];
        }

        int pos, freq = 0;
        
        for (int i = 0; i < LONG_ALFABET; ++i) {
                if (lmf[i] > freq) {
                        pos = i;
                        freq = lmf[i];
                }
        }
        char c = 'a' + pos;
        return c;
}

int main() {
    cout.setf(ios::fixed);
cout.precision(2); 
    int n; 
    cin >> n;
    double suma = 0.0;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        string m = s[i];
        suma += m.size();
    }
    double media = suma / n;
    cout << media << endl;
    
    for (int i = 0; i < n; ++i) {
        if (s[i].size() >= media) cout << s[i] << ": " << lletra_mes_frequent(s[i]) << endl;
    }
}
