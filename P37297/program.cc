#include <iostream>
using namespace std;
int main() {
int n,a,b,c;
cin>>n;
c = n % 10;
n /=10;

b = n%10;
n /=10;
a = n%10;

n=a+b+c;
cout<<n<<endl;
}
