#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);
    int n;
    double z = n;
    double factorial = 1;
    double aprox_of_e = 1;
    while (cin >> n) {

        if (n > 0) {
            for (int i = 1; i < n; ++i) {

                factorial = factorial * i;
                aprox_of_e = aprox_of_e + (1.0 / factorial);
            }
            cout << "With " << n << " term(s) we get " << aprox_of_e << "." << endl;
            aprox_of_e = 1;
            factorial = 1;
        } else
            cout << "With " << n << " term(s) we get "
                 << "0.0000000000"
                 << "." << endl;
    }
}
