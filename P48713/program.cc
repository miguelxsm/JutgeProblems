#include <iostream>
using namespace std;

bool prime(int n) { 
        if (n <= 1) return false;
        else {
            int i = 2;
            while (i * i <= n) {
            if (n % i == 0) return false;
            ++i;
            }
        return true;
        }
}

int main() {
    int a;
    int b;

    cin >> a;

    for (int i = 1; i <= a; ++i) {
        cin >> b;
        prime(b);
        if (not prime(b)) cout << b << " no es primer" << endl;
        else cout << b << " es primer" << endl;
    }
}
    
    
    