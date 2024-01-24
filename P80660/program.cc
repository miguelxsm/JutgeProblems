#include <iostream>
using namespace std;
int main () {
  int n;


      while (cin >> n) {
        int cont = 0;

              while (n != 1) {
                if (n % 2 == 1) n = n*3 +1;
              else n /= 2;
              cont++;
            }
            cout << cont <<endl;

    }

}
