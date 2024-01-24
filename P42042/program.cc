#include <iostream>
using namespace std;


int main() {
    char c;
    cin >> c;

    if (c >= 'A' and c <= 'Z') cout << "uppercase";
    else cout << "lowercase";
    cout << endl;
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or
            c == 'E' or c == 'I' or c == 'O' or c == 'U') cout << "vowel";
    else cout << "consonant";
    cout << endl;
}
