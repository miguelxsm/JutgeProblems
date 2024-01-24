#include <iostream>
#include <vector>
using namespace std;

void bt(string s, int i, const vector<char>& vowels, const vector<char>& consonants, vector<bool>& v_used, vector<bool>& c_used, bool vowel, int n) {
    if (s.size() == n) cout << s << endl;
    else {
        if (!vowel) {
            for (int k = 0; k < consonants.size(); ++k) {
                if (!c_used[k]) {
                    c_used[k] = true;
                    bt(s+consonants[k],i+1,vowels,consonants,v_used,c_used,true, n);
                    c_used[k] = false;
                }
            }
        }
        else {
            for (int k = 0; k < vowels.size(); ++k) {
                if (!v_used[k]) {
                    v_used[k] = true;
                    bt(s+vowels[k],i+1,vowels,consonants,v_used,c_used,false, n);
                    v_used[k] = false;
                }
            }
        }
    }
}

vector<char> read_vector(int n) {
    vector<char> res(n);
    for (int i = 0; i < n; ++i) cin >> res[i];
    return res;
}

int main() {
    int n; cin >> n;
    vector<char> consonants = read_vector(n);
    vector<char> vowels = read_vector(n);
    vector<bool> c_used(n,false);
    vector<bool> v_used(n,false);
    bt("",0,vowels, consonants, v_used, c_used, false, 2*n);
    
}