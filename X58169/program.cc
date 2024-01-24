#include <iostream>
using namespace std;
void infoSequence(int&max, int& lpos) {
    lpos = 1;
    int n;
    cin >> n;
    max = n;
    int anterior;
    int cont_gen = 1;
while (n != 0) {
    if (n >= anterior) {
        max = n;
        lpos = cont_gen;
    }
    anterior = n;
    ++cont_gen;
    cin >> n;
}

    int m;
    cin >> m;
    int pos2 = 1;
    bool encontrado = false;
    while (m != 0 and m != max) {
        ++pos2;
        cin >> m;

    }
    if (m == max) encontrado = true;
    cout << max << ' ' << lpos << ' ';
    if (encontrado) cout << pos2;
    else cout << '-';
    cout << endl;
}

int main() {
    int n;
    int m;
    infoSequence(n,m);
}
