#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nula = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        nula = 0;
        int m;
        cin >> m;
        vector<int> v(m);
        for (int j = 0; j < m; ++j) cin >> v[j];

        for (int j = 1; j < m - 1; ++j) {
            if (v[j - 1] + v[j + 1] == v[j]) ++nula;

        }
         cout << nula << endl;
         total+= nula;
    }
    cout << "Total: " << total << endl;
}
