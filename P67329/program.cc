#include <iostream>
#include <vector>
#include <map>
using namespace std;
const vector<char> letras = {'A', 'C', 'G', 'T'};
void escribir_vector(const vector<char>& v) {
    for (char c : v) cout << c;
    cout << endl;
}

void backtracking(vector<char>& v, int i) {
    if (i == v.size()) escribir_vector(v);
    else {
        for (char c : letras) {
            v[i] = c;
            backtracking(v,i+1);
        }
    }
}

int main() {
    int n; cin >> n;
    vector<char> v(n);
    backtracking(v,0);
}