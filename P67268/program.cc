#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        vector<int> aux(n);
        for (int i = 0; i < n; ++i) aux[i] = v[n - i - 1];
        bool primero = true;
        for (int i = 0; i < n; ++i) {
            if (primero) {
                cout << aux[i];
                primero = false;
            }
            else cout << ' ' << aux[i];
        }
        cout << endl;


    }
}
