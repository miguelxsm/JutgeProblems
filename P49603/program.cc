#include <iostream>
using namespace std;

int main() {
    int n;
    int line = 0;
    int lastLine = 0;
    string s;

    while (cin >> n) {
        string last = " ";
        bool increasing = true;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            if (increasing and s >= last) increasing = true;
            else increasing = false;
            last = s;
        }
        ++line;
        if (increasing) lastLine = line;
    }
    if (lastLine != 0) cout << "The last line in increasing order is " << lastLine << '.' << endl;
    else cout << "There is no line in increasing order." << endl;
}
