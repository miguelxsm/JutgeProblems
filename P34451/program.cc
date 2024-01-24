#include <iostream>
using namespace std;
int main() {
    int n, s, cont = 0;
    cin>>n;
    while (cin>>s) {
        if (s % n == 0) cont++;
    }
    cout<<cont<<endl;

}
