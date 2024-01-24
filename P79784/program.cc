#include <iostream>
using namespace std;
int main() {
    char n;
    int vertical = 0;
    int horizontal = 0;
    while (cin >> n) {
        if (n == 'n') vertical -= 1;
        else if (n == 's') vertical += 1;
        else if (n == 'e') horizontal += 1;
        else horizontal -= 1;
    }
    cout << '(' << horizontal << ", " << vertical << ')' << endl;
}
