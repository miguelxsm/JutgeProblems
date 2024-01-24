#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
    string country_name;
    double gini;
};

struct Q_and_names {
    string country_name;
    vector<double> q;
};

bool comparar(const Info& a, const Info& b) {
    if (a.gini != b.gini) return a.gini < b.gini;
    return a.country_name < b.country_name;
}

//suma los elementos de un vector
double suma_elementos(vector<double> v) {
    double suma = 0;
    for (int i = 0; i < v.size(); ++i) suma += v[i];
    return suma;
}

//pre: quintile_data represents a country income by quintile info
//post: returns the gini coef corresponding to quintile_data
double gini_coef(const vector<double>& quintile_data) {
    vector<double> s(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            s[i] += quintile_data[j] - quintile_data[i];
        }
    }
    return suma_elementos(s) / 500;
}
// lee un vector
void leer(vector<Q_and_names>& v) {
    int cantidad = v.size();
    for (int i = 0; i < cantidad; ++i) {
        vector<double> w(5);
        cin >> v[i].country_name;
        for (int j = 0; j < 5; ++j) cin >> w[j];
        v[i].q = w;
    }
}

void imprimir(const vector<Info> & v) {
    for (int i = 0; i < v.size(); ++i) cout << v[i].country_name << ' ' << v[i].gini << endl;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    int cantidad;
    cin >> cantidad;
    vector<Q_and_names> v(cantidad);
    leer(v);
    vector<Info> w(cantidad);
    for (int i = 0; i < cantidad; ++i) {
        double cof = gini_coef(v[i].q);
        w[i].country_name = v[i].country_name;
        w[i].gini = cof;
    }
    sort(w.begin(), w.end(), comparar);
    imprimir(w);
}
