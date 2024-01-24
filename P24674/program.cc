#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<string>& v, const vector<int>& v2) {
    bool first = true;
    cout << '(';
    for (int i : v2) {
        if (!first) cout << ',';
        cout << v[i];
        first = false;
    }
    cout << ')' << endl;
}


void perm(vector<string>& v2, vector<int>& v, int i, vector<bool>& used) {
    if (i == v.size()) print_vector(v2,v);
    else {
        for (int k = 0; k < int(v.size()); ++k) {
            if (!used[k]) {
                used[k] = true;
                v[i] = k;
                perm(v2,v,i+1,used);
                used[k] = false;
            }
        }
    }
}

void read_input(vector<string>& v) {
    for (int i = 0; i < int(v.size()); ++i) {
        cin >> v[i];
    }
}

int main() {
    int n; cin >> n; vector<string> v(n);
    read_input(v);
    vector<int> v2(n); vector<bool> used(n, false);
    perm(v,v2,0,used);
}