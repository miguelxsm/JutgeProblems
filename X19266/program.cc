#include <iostream>
using namespace std;
int main() {

    int h1,m1,h2,m2; // declarem variables de hores y minuts
    int h3,m3; // declarem les variables de resultat
    cin >> h1 >> m1 >> h2 >> m2; // 2 45 2 44

    //declarem les condicions per la resta
    if (m1 > m2) {
        m3 = 60 + m2 - m1; 
    }

    else {
    m3 = m2 - m1;
    } 
    if (m1 > m2) h1 = h1 + 1;
    
    if (h1 > h2) {
        h3 = 24 + h2 - h1; // 24 +2 - 3 = 23
    }
    else {
        h3 = h2 - h1;
    } 

    //instruccions per la sortida
    if (h3 < 10) cout << 0;
    cout << h3 << ':';
    if (m3 < 10) cout << 0;
    cout << m3 << endl;

}