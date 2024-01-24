#include <iostream>
using namespace std;
int main() {
int a, b;
  while (cin>>a>>b) {
    if (b == 0) cout<<1<<endl;
    else {
    int a2;
    a2 = a;
    for (int i = 1 ; i < b ; i++) {
      a2 = a2 * a;
    }
    cout<<a2<<endl;
    }

  }
}
