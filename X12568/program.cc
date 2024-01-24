#include <iostream>
using namespace std;
// int main() {
//
//     int n;
//     cin >> n;
//         //parte de arriba
//         for (int i = 0; i < n; ++i) {
//             cout << '*';
//         }
//         cout << endl;
//
//         // lineas a tratar
//         for (int i = 0; i < n; ++i) {
//
//             // espacios antes del primer asterisco
//             for (int j = 1 ; j <= i ; ++j) {
//                 cout << ' ';
//             }
//             cout << '*';
//
//             // espacios del final
//             for (int j = n - 3; j != 0 ; --j) {
//                 cout << ' ';
//             }
//             cout << "*" << endl;
//
//             cout << endl;
//
//     }
// }


int main(){
    int n; cin>> n;

    for(int i = 0; i<n; ++i)cout<<"*";
    cout << endl;

    for(int i = 1; i<n; ++i){
        for(int j = 0; j<i; ++j){
            cout << " ";
        }
        cout << "*";

        for(int k = i+1; k<n-1; ++k )cout << " ";
        if(i != n-1 )cout << "*"<< endl;
    }
    cout << endl; 



}
