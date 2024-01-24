#include <iostream>
using namespace std;

 int mcd(int a, int b) {
    if (b == 0) return a;
    else return mcd(b, a % b);

}
struct Fraccio {
     int num, den;   // sempre estrictament positius
     };

 Fraccio suma(const Fraccio& x, const Fraccio& y) {
     Fraccio sol;
     sol.num = x.num*y.den + y.num*x.den;
     sol.den = x.den*y.den;
     int mcdh = mcd(sol.num, sol.den);
     sol.num /= mcdh; sol.den /= mcdh;
     return sol;
 }

  int main() {
     Fraccio x;
     Fraccio y;
     char barra;
     char signo;
     cin >> x.num >> barra >> x.den >> signo;
     while (signo != '=') {
         cin >> y.num >> barra >> y.den >> signo;
         x = suma(x,y);
     }
     int mcdh = mcd(x.num, x.den);
     cout << x.num/mcdh << '/' << x.den/mcdh << endl;



 }
