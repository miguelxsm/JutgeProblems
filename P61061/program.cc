#include <iostream>
using namespace std;
int main() {
    int n;

        while (cin >> n) {
            if (n < 10) {
                cout << "The product of the digits of " << n << " is " << n << '.' << endl << "----------" << endl;
            }
            else {
                while (n / 10 != 0){
                    int ndup;
                    ndup = n;
                    cout << "The product of the digits of " << n << " is ";
                    n = 1;
                    while (ndup != 0) {
                        n *= ndup % 10;
                        ndup /= 10;
                        }
                    cout << n << '.' << endl;
                }
                cout << "----------" << endl;
            }
        }
    }
