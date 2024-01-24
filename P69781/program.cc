#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int collatz_sequence(int x, int y, int n, map<int,int>& m, int cont) {
    auto it = m.find(n);

    if (n > pow(10,8)) return n;
    if (it != m.end()) {
        //solucion
        return cont - it->second;
    }
    if (n % 2 == 0) {
        m.insert({n, cont});
        n /= 2;
        n += x;
    }
    else {
        m.insert({n, cont});
        n *= 3;
        n += y;
    }
    return collatz_sequence(x,y,n,m, ++cont);
}

int main() {
    int x,y,n;
    while (cin >> x >> y >> n) {
        int n_seg;
        if (n % 2 == 0) n_seg = n/2 + x;
        else n_seg = 3*n + y;
        map<int,int> posiciones; // map<numero_seq,pos>
        posiciones.insert({n, 0});
        cout << collatz_sequence(x,y,n_seg,posiciones, 1) << endl;
    }
    
}