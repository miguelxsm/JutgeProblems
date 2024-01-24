#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Mat;

void read_matrix (Mat& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) cin >> v[i][j];
    }
}

bool quadrat_magic(const vector< vector<int> >& t) {

    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (t[i][j] > t.size()*t.size()) return false;
        }
    }

    int suma = 0;
    for (int i = 0; i < t.size(); ++i) {
        suma += t[0][i];
    }
    // filas
    for (int i = 0; i < t.size(); ++i) {
        int suma2 = 0;
        for (int j = 0; j < t[0].size(); ++j) {
            suma2 += t[i][j];
        }
        if (suma != suma2) return false;
    }

    //columnas
    for (int j = 0; j < t.size(); ++j) {
        int suma2 = 0;
        for (int i = 0; i < t[0].size(); ++i) {
            suma2 += t[i][j];
        }
        if (suma != suma2) return false;
    }

    // diagonal principal
    int suma_diagonal = 0;
    for (int i = 0; i < t.size(); ++i) {
        suma_diagonal += t[i][i];
    }
    if (suma_diagonal != suma) return false;

    suma_diagonal = 0;
    //diagonal secundaria
    for (int i = 0; i < t.size(); ++i) {
        suma_diagonal += t[i][t.size() - 1 - i];
    }
    if (suma_diagonal != suma) return false;
    return true;

}



int main() {
    int n;
    while (cin >> n) {
        Mat v(n, vector<int>(n));
        read_matrix(v);
        if (quadrat_magic(v)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}
