#include <iostream>
using namespace std;
int main() {

    int i;
    cin >> i;
    int x;
    int cont = i;

    while (cin >> x) {
        if (cont == 1) cout << "At the position " << i << " there is a(n) " << x << '.' << endl;
        cont--;

    }
}
