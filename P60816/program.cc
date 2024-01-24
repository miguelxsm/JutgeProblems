#include <iostream>
using namespace std;
int main() {

    int n, m;
    cin>>n;
    if (n == 0) cout<<"0";
    else
        while (n !=0) {
        m = n%16;
          if (m == 10) cout<<"A";
          else if (m == 11) cout<<"B";
          else if (m == 12) cout<<"C";
          else if (m == 13) cout<<"D";
          else if (m == 14) cout<<"E";
          else if (m == 15) cout<<"F";
          if (m < 10) cout<<m;
          n /=16;
        }
        cout<<endl;
    
}
