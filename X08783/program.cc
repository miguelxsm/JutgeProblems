#include <iostream>
using namespace std;

int num_digits(int b, int n, int cont)
{
    if (n == 0)
        return cont;
    else
        return num_digits(b, n / b, cont + 1);
}

int main()
{
    int b, n;

    while (cin >> b >> n) {
        cout << num_digits(b, n, 0) << endl;
    }
}
