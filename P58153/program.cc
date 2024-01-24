#include <iostream>
using namespace std;
int main() {
    
    cout.setf(ios::fixed);
    cout.precision(10);

    int n1 , n2 ;
    while (cin >> n1 >> n2) {
        double sumador = 0;
        for (int i = n2+1 ; i <= n1 ; ++i) {
            sumador += 1.0/i;
        }
        cout << sumador << endl;
    }
    
}