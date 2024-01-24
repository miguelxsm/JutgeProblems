#include <iostream>
using namespace std;
int main() {
double n, s = 0;
cout.setf(ios::fixed);
    cout.precision(4);
cin>>n;
for (int i = 1; i <= n ; i++) {

s += (1.0/i);
    }

  cout<<s<<endl;
  }
