#include <iostream>
using namespace std;
int main() {
    cout.precision(4);
	cout.setf(ios::fixed);

int n, m;
double seq;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double min, max;
        double avar = 0;
        min = seq;
        max = seq;
        cin >> m;
        bool primero = true;
        for (int j = 0; j < m; ++j) {
            cin >> seq;
            if (primero) {
                min = seq;
                max = seq;
                primero = false;
            }
            avar+= seq;
            if (min < seq) min = seq;
            if (max > seq) max = seq;
        }
        cout << max << ' ' << min << ' ' << avar / m << endl;
    }
}
