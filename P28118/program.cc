#include <iostream>
#include <math.h>
using namespace std;

double distancia(double x1, double y1, double x2, double y2) {
    cout.setf(ios::fixed);
    cout.precision(4);
    double d1;
    double d2;
    d1 = x1 - x2;
    d2 = y1 - y2;
    return sqrt(d1*d1 + d2*d2);
}

int main() {
    string s;
    while (cin >> s) {
        double suma = 0.0;
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        const double d_inicialx = x1;
        const double d_inicialy = y1;
        while (!(d_inicialx == x2 and d_inicialy == y2)) {
            suma += distancia(x1,y1,x2,y2);
            x1 = x2;
            y1 = y2;
            cin >> x2 >> y2;
        }
        suma += distancia(x1,y1,x2,y2);
        cout << "Trajecte " << s << ": " << suma << endl;
    }

}
