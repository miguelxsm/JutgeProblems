#include <iostream>
using namespace std;
int main() {
int n;
cin>>n;

for (int i = 1 ; i<n+1 ; ++i) {
int m;
m = n*i;
cout<<n<<" x "<<i<<" = "<<m<<endl;
}
}
