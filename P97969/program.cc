#include <iostream>
using namespace std;
int main() {

    char n; int cont = 0;
    while (cin>>n) {
      if (n == 'a') ++cont;
    }
    cout<<cont<<endl;
}
