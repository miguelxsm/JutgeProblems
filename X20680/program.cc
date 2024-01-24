#include <iostream>
#include <vector>
#include <map>
using namespace std;


void write_vector(const vector<char>& v) {
    for (char c : v) cout << c;
    cout << endl;
}

void backtracking(vector<char>& v, int i, int c, vector<char>& lletres, int consec) {
    if (v.size() == i) write_vector(v);
    else {
        for (int k = 0; k < 3; ++k) {
            bool consecutivo = (i > 0 && v[i-1] == lletres[k]);
            int new_consec = (consecutivo ? consec + 1: 1);
            if (new_consec <= c) {
                v[i] = lletres[k];
                backtracking(v,i+1,c,lletres,new_consec);
            }

        }
    }
}

int main() {
    int n, c;
    while (cin >> n >> c) {
        vector<char> v(n);
        vector<char> lletres = {'x', 'y', 'z'};
        backtracking(v,0,c,lletres, 0);
        cout << "--------------------" << endl;
    }
}