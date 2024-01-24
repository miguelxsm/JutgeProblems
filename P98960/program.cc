#include <iostream>
using namespace std;


int main() {
    char c;
    cin >> c;
    if (c >= 'a' && c <= 'z') c = c +'A' - 'a';
    else if (c >= 'A' && c <= 'z') c = c + 'a' - 'A';
    cout << c << endl;
}
