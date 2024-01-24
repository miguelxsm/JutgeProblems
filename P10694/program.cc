#include <iostream>
using namespace std;
void imprimir(int n) {
    if (n == 1) cout << '*' << endl;
    else {
        imprimir (n - 1);
        imprimir (n - 1);
        for (int i = 0; i < n; ++i) cout << '*';
        cout << endl;


    }

}

int main() {
    int n;
    cin >> n;
    imprimir(n);
}
