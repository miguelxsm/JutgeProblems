#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n;
    cout.setf(ios::fixed);
        cout.precision(6);
    cin>>n;
    for (int i = 0 ; i <=n ; i++) {
        string shape;
        cin >> shape;
        if (shape == "cercle" ) {
            double r;
            cin >> r;
            cout<<r*r*M_PI<<endl;
        }
        if (shape == "rectangle") {
            double l,h;
            cin>>l>>h;
            cout<<l*h<<endl;
        }
      }
  



}
