#include <iostream>
#include <vector>
using namespace std;

void escribir_vector(const vector<int>& v) {
    bool primero = true;
    for (int i : v) {
        if (!primero) {
            cout << ' ';
        }
        cout << i;
        primero = false;
    }
    cout << endl;
}

void combinacion(vector<int> v, int i) {
    if (i == v.size()) escribir_vector(v);
    else {
        v[i] = 0; combinacion(v, i+1);
        v[i] = 1; combinacion(v, i+1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    combinacion(v, 0);
}