#include <iostream>
using namespace std;
void reverse(string s) {
    if (cin >> s and s != "end") {
        reverse(s); 
        cout << s << endl;
    }
}

int main() {
    string s;
    reverse(s);
}