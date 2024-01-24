#include <iostream>
using namespace std;
int main() {
  int x;
  cin>>x;
  if (x<10 && x<=0) {
    cout<<"fa fred" <<endl;
    cout<<"l'aigua es gelaria" <<endl;
  }
  else if (x<10 && x>0) {
    cout<<"fa fred" <<endl;
  }

  else if (x<=30 && x>=10) {
  cout<<"s'esta be" <<endl;
}

else if (x>30 && x<100) {
  cout<<"fa calor" <<endl;
}

  else if (x>30 && x>=100) {
  cout<<"fa calor" <<endl;
  cout<<"l'aigua bulliria" <<endl;
}


}
