#include <iostream>
#include <math.h>
using namespace std;

double dist_or(double x, double y) {
    double resultado;
    resultado = sqrt(x*x + y*y);
    return resultado;
    }
int main() {
    cout.setf(ios::fixed);
    cout.precision(5);
        int n, m;
        while (cin >> n >> m) {
            cout << dist_or(n, m) << endl;
        }

}
