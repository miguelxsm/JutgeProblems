#include <iostream>
using namespace std;

 int reduction_of_digits( int x) {
    if (x <= 9) return x;
    else return reduction_of_digits(reduction_of_digits(x/10) + x % 10);
}
