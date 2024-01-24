#include <iostream>
using namespace std;
void reverse(int& cont) {
    string s;
    if (cin >> s) {
        ++cont;
        reverse(cont);
    }
    if (cont < -1) cout << s << endl;
    cont = cont - 2;

}

int main() {
    int cont = 0;
    reverse(cont);
}
