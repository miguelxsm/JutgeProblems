#include <iostream>
using namespace std;
int main () {
  int a, b;
  cin>>a>>b;
  if (b < a) cout<<endl;
  else {
    while (a < b) {
      cout<<a<<",";
      a++;
    }
  }
  if (a == b) cout<<b<<endl;
}
