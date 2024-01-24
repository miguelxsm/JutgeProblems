#include <iostream>
using namespace std;
int main() {

      int n, m = 0, s; cin >> n; s = n;
      if (n == 0) cout<< "0 ES TXATXI"<<endl;
      else {

          while (s != 0) {
              m += s % 10;
              s /= 100;
            }


      if (m % 2 == 0) cout<< n << " ES TXATXI"<<endl;
        else cout<< n << " NO ES TXATXI"<<endl;
}
}
