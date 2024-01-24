#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v) {
    double suma = 0.0;
    for (int i = 0; i < v.size(); ++i) {
        suma += v[i] * u[i];
    }
    return suma;
}
