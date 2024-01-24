#include <iostream>
using namespace std;
int main() {

    int n, m;
    cin>>n;
    if (n == 0) {
      cout<<"0"<<endl;
    }
    else {
      while (n != 0) {
      m = n % 10;
        n /= 10;
        cout<<m;
      }
      cout<<endl;
    }

}
