#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v(1001,0);
    int long n;
    cin >> n;
    int long numero;
    for (int i = 0; i < n; ++i) {
        cin >> numero;
        ++v[numero - 1000000000];
    }

    for (int i = 0; i < 1001; ++i) {
        if (v[i] != 0) cout << i + 1000000000 << " : " << v[i] << endl;
    }
}
