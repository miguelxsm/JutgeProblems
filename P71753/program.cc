#include <iostream>
using namespace std;
int main() {

    int m;
    while (cin >> m) {
        bool primero = true;
        int seq;
        int max = 0;
        for (int i = 0; i < m; ++i) {
            cin >> seq;
            if (primero) {
                max = seq;
                primero = false;
            }
            if (max < seq) max = seq;
        }
        cout << max << endl;
    }

    }
