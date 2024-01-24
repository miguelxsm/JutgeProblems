#include <iostream>
using namespace std;
int main() {

    char c;
    int cont = 0;
    bool quit = true;
    while (cin >> c and quit) {
          if (c == '(') ++cont;
          else --cont;
          if (cont < 0) quit = false;
        }
    if (cont == 0 and quit) cout << "yes" << endl;
    else cout << "no" << endl;
}
