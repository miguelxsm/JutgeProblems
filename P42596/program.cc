#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector< vector<int> > Matrix;

void min_max(Matrix& mat, int& minimum, int& maximum) {
    int f = mat.size();
    int c = mat[0].size();
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] < minimum) minimum = mat[i][j];
            if (mat[i][j] > maximum) maximum = mat[i][j];
        }
    }
}

int main() {
    int f,c;
    int cont = 1;
    int resta = INT_MIN;
    int cont2 = 0;
    while (cin >> f >> c) {
        Matrix mat(f, vector<int>(c));
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        min_max(mat,minimum,maximum);
        if (resta < maximum - minimum) cont2=cont;
        resta = max(resta, maximum - minimum);
        ++cont;
    }

    cout << "la diferencia maxima es " << resta << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << cont2 << endl;
}
