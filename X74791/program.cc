#include <iostream>
using namespace std;
int main() {

    int n;
    int cont = 0;
    while (cin >> n && n != -1) {
        int primero, ultimo;
        ultimo = n % 10;
        if (n == 0) primero = 0;
        else {
            int ndup;
            ndup = n;
            while (ndup > 0) {
                if (ndup / 10 == 0) primero = ndup % 10;
                ndup /= 10;
            }
        }
        if (primero == ultimo) {cout << n << endl; ++cont;}
    }
    cout << "total: "<< cont<< endl;
}
