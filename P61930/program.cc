#include <iostream>
using namespace std;

int sum_of_digits(int n) {
    if (n <= 9) return n;
    else return sum_of_digits(n % 10 + sum_of_digits(n / 10));
}

bool is_multiple_3(int n) {
    return (sum_of_digits(n) == 3 || sum_of_digits(n) == 6 || sum_of_digits(n) == 9);
}


int main() {
    int n;
    cin >> n;
    cout << is_multiple_3(n) << endl;
}
