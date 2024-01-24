#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparar(int a, int b) {
    return a > b;
}


void vector_ordenar(const vector <int> v, vector<int>& pares, vector<int>& impares) {
    int n = v.size();

    for (int i = 0; i < n; ++i) {
        if (v[i] % 2 == 0) pares.push_back(v[i]);
        else impares.push_back(v[i]);
    }

    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end(), comparar);

    //fusionamos
    vector <int> solucion(pares.size() + impares.size());
    for (int i = 0; i < pares.size(); ++i) {
        solucion[i] = pares[i];
    }

    for (int i = 0; i < impares.size(); ++i) {
        solucion[i] = impares[i];
    }
}

int  main() {
    int n;
        while (cin >> n) {
        vector <int> v;
        while (n != 0) {
            v.push_back(n);
            cin >> n;
        }
        vector<int> pares;
        vector<int> impares;
        vector_ordenar(v, pares, impares);
        bool primero = true;
        for (int i = 0; i < pares.size(); ++i) {
            if (primero) {
                cout << pares[i];
                primero = false;
            }
            else cout << ' ' << pares[i];
        }
        cout << endl;
        primero = true;

        for (int i = 0; i < impares.size(); ++i) {
            if (primero) {
                cout << impares[i];
                primero = false;
            }
            else cout << ' ' << impares[i];
    }
        cout << endl;
    }
}
