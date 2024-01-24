#include <iostream>
using namespace std;
int main() {

    //declarem les variables necessàries
    string paraula,seq;

    int cont = 1;
    cin >> paraula;
    while (cin >> seq and seq != paraula) {
        
        if (seq != paraula) ++cont;

        
    }

    if (seq == paraula) cout << cont << endl;
    else cout << "No existe" << endl;

}