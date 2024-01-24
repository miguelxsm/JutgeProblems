#include <iostream>
#include <vector>
using namespace std;

void escribir_vector(const vector<int>& v) {
    bool primero = true;
    for (int i : v) {
        if (!primero) cout << ' ';
        cout << i;
        primero = false;
    }
    cout << endl;
}

// k = cantidad de unos que queremos
void combinacion(vector<int>& v, int i, int k, int qt_ceros, int qt_unos) {
    if (v.size() == i) escribir_vector(v);
    else {
        if (qt_ceros < int(v.size()) - k) {
            v[i] = 0;
            combinacion(v,i+1,k,qt_ceros+1,qt_unos);
        }
        if (qt_unos < k) {
            v[i] = 1;
            combinacion(v,i+1,k,qt_ceros,qt_unos+1);
        }

    }
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    combinacion(v,0,k,0,0);
}