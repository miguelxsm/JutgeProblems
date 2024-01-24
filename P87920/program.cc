#include <iostream>
#include <vector>
using namespace std;

// funcion que retorna si algun numero es la suma del resto;
bool suma_vector(vector<int> v, int suma) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (suma == 2*v[i]) return true;
    }
    return false;
}

int main() {
    int n;

    while (cin >> n) {
        int suma = 0;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            suma += v[i];
        }
        if (suma_vector(v,suma)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }


}
