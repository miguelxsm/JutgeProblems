#include <iostream>
using namespace std;
int main() {

    int n, m;
    int cont = 0;
    while (cin >> n >> m) {
      if (cont != 0) cout << endl;
      int c = 9;
      for (int i = 0; i < n; ++i) {

            for (int j = 0; j < m; ++j) {
                cout << c;
                c--;
                if (c < 0) c = 9;
            }
            cout << endl;
        }
        ++cont;
    }
}
