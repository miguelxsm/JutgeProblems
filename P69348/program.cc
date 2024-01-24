#include <iostream>
#include <vector>
using namespace std;

void escribir_vector(const vector<int>& v) {
    cout << '(';
    bool primero = true;
    for(int i : v) {
        if (!primero) cout << ',';
        cout << i;
        primero = false;
    }
    cout << ')' << endl;
}

void permutacion(vector<int>& v, vector<bool>& used, int i) {
    if (i == v.size()) escribir_vector(v);
    else {
        for (int k = 1; k <= v.size(); ++k) {
            if (!used[k]) {
                used[k] = true;
                v[i] = k;
                permutacion(v,used,i+1);
                used[k] = false;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    vector<bool> used(n,false);
    permutacion(v,used,0);
}