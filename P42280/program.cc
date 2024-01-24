#include <iostream>
using namespace std;
int main() {

    int f, c;
    int suma = 0;
    cin >> f >> c;
    for (int i = 0 ; i < f ; i++) {
        for (int j = 0 ; j < c; j++) {
          char c;
          cin >> c;
          c = int (c) - '0';
            suma += c;
          }
        }
  cout << suma << endl;
  }
