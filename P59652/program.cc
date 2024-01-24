#include <iostream>
using namespace std;
int mcd(int a, int b) {
    while (b > 0) {
    int temp;
    temp = b;
    b = a % b;
    a = temp;
    }
    return a;

}
void read_rational(int& num, int& den) {
    char x;
    cin >> num >> x >> den;
    int mcdAB = mcd(num, den);
    num /= mcdAB;
    den /= mcdAB;
}

int main() {
    int num, den;
    read_rational(num,den);
    cout << num << ' ' << den << endl;
}
