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

bool is_valid_date(int d, int m, int y) {
    if (d < 1 or d > 31 or m > 12 or m < 1) return false;
    else {
        if (d == 29 and m == 2) {
            if (not is_leap_year(y)) return false;
        }

        if (d > 29 and m == 2) return false;
        if ((m == 4 or m == 6 or m == 9 or m == 11) and d > 30) return false;
        else return true;

    }


}

int main() {
    int d, m, y;
        while (cin >> d >> m >> y) {
        cout << is_valid_date(d, m, y) << endl;
    }
}
