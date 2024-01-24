#include <iostream>
using namespace std;
int main() {
  int n, hour, min;
  cin>>n;
  hour = n/3600; n%=3600;
  min = n/60; n%=60;

  cout<<hour<<" "<<min<<" "<<n<<endl;

}
