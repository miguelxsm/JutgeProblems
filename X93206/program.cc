#include <iostream>
#include <vector>
using namespace std;

bool repetido(vector<string> v, int pos) {
    for (int i = 0; i < pos; ++i) {
        if (v[i] == v[pos]) return false;
        }
        return true;
    }


vector<bool> escribe(vector<string> v) {
    int n = v.size();
    vector<bool> w(n);
    for (int i = 0; i < n; ++i) {
        w[i] = repetido(v,i);
        }
        return w;
    }

int main() {
    int n;
    while (cin >> n) {
        vector<string> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        vector<bool> comp = escribe(v);
        for (int i = 0; i < n; ++i) {
            if (comp[i]) cout << v[i] << endl;
        }
        cout << endl;
    }

}
