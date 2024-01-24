#include <iostream>
using namespace std;
int main() {
  int x,y;
  cin>>x>>y;
if (x<y) {
  while (y >= x) {
  cout<<y<<endl;
  --y;
}
}
else {
  while (x >= y) {
    cout<<x<<endl;
    --x;
  }
}
}
