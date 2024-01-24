#include <iostream>
using namespace std;


int exp_rapida(int n, int k, int mod) {
    if (k == 0) return 1;
    else if (k == 1) return n % mod;
    else if (k % 2 == 0) {
        int resultado = exp_rapida(n, k/2, mod);
        return (resultado*resultado) % mod;
    }
    else {
        return n * exp_rapida(n, --k, mod) % mod;
    }
}

int main() {
    int n,k,mod;
    while (cin >> n >> k >> mod) cout << exp_rapida(n,k,mod) << endl;
}