#include <iostream>
#include <vector>
using namespace std;

void escribir_vector(const vector<int>& v) {
    for (int x : v) cout << x;
    cout << endl;
}

void backtracking(vector<int>& v, vector<int>& freq, int c, int i, bool seguido) {
    if (i == v.size() && seguido) escribir_vector(v);
    else {
        for (int k = 1; k <= 3; ++k) {
            bool rep = (i > 0 && v[i-1] == k); //devuelve true si justo el elemento anterior es igual que el que se esta tratando, false en caso contrario
            if (freq[k-1] >= c || (seguido && rep)) continue;
            
            if (!seguido && rep) {
                freq[k-1]++;
                v[i] = k;
                backtracking(v,freq,c,i+1,true);
                freq[k-1]--;
            }
            else {
                freq[k-1]++;
                v[i] = k;
                backtracking(v,freq,c,i+1,seguido);
                freq[k-1]--;
            }
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> res(3*n);
        vector<int> freq(3,0);
        backtracking(res,freq,n,0,false);
        cout << "**********" << endl;
    }
}
