#include <iostream>
#include <vector>
using namespace std;
int common_elements(const vector<int>& x, const vector<int>& y) {
    int cont = 0;
    for (int i = 0; i < x.size(); ++i) {
        int izquierda = 0;
        int derecha = y.size() - 1;

        while (izquierda <= derecha) {
            int m = (izquierda + derecha) / 2;
            if (y[m] > x[i]) derecha = m - 1;
            else if (y[m] < x[i]) izquierda = m + 1;
            else {
                cont = cont + 1;
                break;
            }
        }
    }
    return cont;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> y[i];
    cout << common_elements(x,y) << endl;
}
