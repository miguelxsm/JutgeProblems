#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void write_vector(const vector<char>& v) {
    for (char c : v) cout << c;
    cout << endl;
}

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void backtracking(vector<char>& v, const vector<char>& lletres, int i, bool vowel) {
    if (i == v.size()) write_vector(v);
    else {
        for (char c : lletres) {
            if (is_vowel(c)) {
                if (vowel) continue;
                v[i] = c;
                backtracking(v,lletres,i+1,true);
            }
            else {
                v[i] = c;
                backtracking(v,lletres,i+1,false);
            }
        }

    }
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        vector<char> lletres(m);
        for (int i = 0; i < m; ++i) cin >> lletres[i];
        sort(lletres.begin(), lletres.end());
        vector<char> v(n);
        backtracking(v,lletres,0,false);
        cout << string(10,'-') << endl;
    }
}