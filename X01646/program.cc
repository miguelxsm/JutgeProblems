#include <iostream>
using namespace std;
int main() {

    int base, n;
    cin >> base;
    while (cin >> n) {
          int suma = 0;
          cout << n << ": ";
          while (n != 0) {
              suma += n % base;
              n /= base;
            }
          cout<<suma<<endl;

    }

}
