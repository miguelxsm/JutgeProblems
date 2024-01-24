#include <iostream>
using namespace std;
int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    int a, b, k;



    while (cin >> a >> b >> k) {
        double suma = 0;
        for (int i = 0; (a + k*i) <= b; ++i) {
            suma += 1.0 / (a + k*i) ;
        }
        cout << suma << endl;
    }
}
