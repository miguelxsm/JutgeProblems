#include <iostream>
using namespace std;
int main() {
  int n, cont = 1;
    cin>>n;
    cout<<"The number of digits of "<<n<<" is ";
    while (n > 9) {
      n /=10;
      ++cont;
    }
    cout<<cont<<"."<<endl;
  }
