#include <iostream>
using namespace std;
int main() {

    string paraula1;
    cin >> paraula1;
    string paraula2;
    int contmax = 0;
    int cont1 = 1;
    while (cin >> paraula2) {
        if (paraula2 != paraula1) cont1 = 0;
        else cont1++;

        if (cont1 > contmax) contmax = cont1;
    }
    if (contmax == 0) contmax = 1;
    cout << contmax << endl;
}
