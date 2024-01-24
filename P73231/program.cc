#include <iostream>
using namespace std;
int max4(int a, int b, int c, int d) {
int max1, max2;
if (a > b) max1 = a;
else max1 = b;

if (c > d) max2 = c;
else max2 = d;

if (max2 > max1) max1 = max2;
return max1;
}

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << max4(a, b, c, d) << endl;
}
