#include <iostream>
using namespace std;

bool is_leap_year(int year) {
    if (year % 100 == 0) {
    year /= 100;
      if (year % 4 == 0) return true;
      else return false;
      }

    else if (year % 4 == 0) return true;
    else return false;

    }

int main() {
    int year;
    cin >> year;
    cout << is_leap_year(year) << endl;
}
