#include <iostream>
using namespace std;
int main() {
    int n;
    bool coso = false;
    while (cin >> n) {
        if(coso ){
            cout << endl; 
        }
        coso =true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << n;
            }
            cout << endl;
        }
    }

}
