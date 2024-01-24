#include <iostream>
using namespace std;
int main () {
  string n,m;
  cin>>n>>m;
  if (n<m) cout<<n<<" < "<<m<<endl;
  else if (n>m) cout<<n<<" > "<<m<<endl;
  else cout<<n<<" = "<<m<<endl;
}
