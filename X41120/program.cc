#include <iostream>
#include <vector>
using namespace std;

//función que me retorna los picos
vector<int> calcula_cimas(const vector<int>& v) {

    int n = v.size();
    vector<int> w(n);
    int j = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
            w[j] = v[i];
            ++j;
        }
    }
    return w;

}

int main() {
    // leer vector
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector <int> aux = calcula_cimas(v);

    //calculo cuántos 0's hay en el vector para descartarlos
    int size = aux.size();
    for (int i = 0; i < aux.size(); ++i) {
        if (aux[i] == 0) --size;
    }
    vector<int> w(size);
    for (int i = 0; i < size; ++i) {
        w[i] = aux[i];
    }
    cout << size << ':';
    for (int i = 0; i < w.size(); ++i) cout << ' ' << w[i];
    cout << endl;
    bool primero = true;
    bool hay = false;
    for (int i = 0; i < size; ++i) {
        if (w[i] > w[size - 1]) {
            hay = true;
            if (primero) {
                cout << w[i];
                primero = false;
            }
            else cout << ' ' << w[i];
        }
    }
    if (not hay) cout << '-';
    cout << endl;
}
