#include <iostream>
using namespace std;
int main () {
double x;
cin>>x;
if (x == int(x))
  cout<<int(x)<< ' '<<int(x) << ' ' << int(x);
  else {
    cout<<int(x)<<' ' <<int(x) + 1 << ' ';
    if (x-int(x) < 0.5)
      cout<<int(x);
      else cout<<int(x) + 1;
  }
  cout<<endl;
}
