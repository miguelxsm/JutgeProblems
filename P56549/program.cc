#include <iostream>
using namespace std;

void hex (long int n) {
if (n < 16) {
    if (n % 16 == 10) cout << 'A';
    else if (n % 16 == 11) cout << 'B';
    else if (n % 16 == 12) cout << 'C';
    else if (n % 16 == 13) cout << 'D';
    else if (n % 16 == 14) cout << 'E';
    else if (n % 16 == 15) cout << 'F';
    else cout << n;
}
else {
    hex (n / 16);
    if (n % 16 == 10) cout << 'A';
    else if (n % 16 == 11) cout << 'B';
    else if (n % 16 == 12) cout << 'C';
    else if (n % 16 == 13) cout << 'D';
    else if (n % 16 == 14) cout << 'E';
    else if (n % 16 == 15) cout << 'F';
    else cout << n % 16;
}
}

void octal (long int n) {
if (n < 8) cout << n;
else {
    octal (n / 8);
    cout << n % 8;
}
}

void binario (long int n) {
if (n < 2) cout << n;
else {
    binario (n / 2);
    cout << n % 2;
}
}
int main() {
    int long n;
    while (cin >> n) {
    cout << n << " = ";
    binario(n); cout << ", "; octal(n); cout << ", "; hex(n); cout << endl;
}
}
