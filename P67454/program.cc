#include <iostream>
using namespace std;
int main() {

    char c;
    bool punto = false;
    int cont = 0;
    while (cin >> c and not punto) {
        if (c == 'a') cont++;

        else if (c == '.') punto = true;
    }
    cout << cont << endl;
}
