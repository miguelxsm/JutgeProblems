#include <iostream>
using namespace std;

int main() {
    int cantidad;
    cin >> cantidad;
    for (int i = 0; i < cantidad; ++i) {
        int n1,n2;
        cin >> n1 >> n2;
        int min = 0;
        int seq = 0;
        while (n2 != 0) {
            if (n2 > n1 and (min == 0 or min > n1)) ++seq;
            if (min == 0 or n1 < min) min = n1;
            n1 = n2;
            cin >> n2;
        }
        cout << seq << endl;
    }
}
