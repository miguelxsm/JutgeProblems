#include <iostream>
using namespace std;
int main () {

  cout.setf(ios::fixed);
      cout.precision(2);

      int cont = 0;
      double n, media, m = 0;
      while (cin >> n) {
          m += n;
          cont++;
      }
      cout<< m / cont <<endl;
}
