#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    int m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> m; v[i] = m;
    }
    int cont = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == v[n - 1]) ++cont;
    }

    cout << cont - 1 << endl;
}