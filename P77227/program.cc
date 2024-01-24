#include <iostream>
#include <vector>
using namespace std;


string sortida(int p, vector<int>& v) {
    int aux = v[p];
    while (p >= 0 and p < v.size()) {
        if (v[p] == 0) return "mai";
        aux = v[p];
        v[p] = 0;
        p += aux;
    }
    if (p < 0) return "esquerra";
    else return "dreta";
}
