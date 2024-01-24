#include <iostream>
using namespace std;
int main() {

    string p;
    int cont = 0;
    while (cin >> p) {
        if (p == "hello") ++cont;
    }
    cout << cont << endl;
}
