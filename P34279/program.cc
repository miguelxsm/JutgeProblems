#include <iostream>
using namespace std;
int main() {
int hour,min,sec;
cin>>hour>>min>>sec;

sec += 1;
if (sec>=60) {
  min++;
sec=0;
}

if (min>=60) {
   hour++;
min=0;
}
if (hour>=24) hour=0;

if (hour<10) cout<<"0"<<hour<<":";
else cout<<hour<<":";

if (min<10) cout<<"0"<<min<<":";
else cout<<min<<":";

if (sec<10) cout<<"0"<<sec<<endl;
else cout<<sec<<endl;
}
