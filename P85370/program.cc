#include <iostream>
using namespace std;
int main () {
  cout.setf(ios::fixed);
  cout.precision(4);

    double c, p, t;
    string interes;

    cin>>c>>p>>t>>interes;
    if (interes == "simple") {
            c += t*p*c/100;
            cout.setf(ios::fixed);
            cout.precision(4);
            cout<<c<<endl;
          }
    else {
      for (int i = 1 ; i <= t ; i++) {
        c += c*p/100;
      }
      
      cout<<c<<endl;

    }
  }
