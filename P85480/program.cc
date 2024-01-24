#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    if (n <= 1) return false;
    else {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
    }
    return true;
}

bool suma(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int suma_vector = v[i] + v[j];
            if (prime(suma_vector)) return true;
        }
    }
    return false;
}
int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        if (suma(v)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}
