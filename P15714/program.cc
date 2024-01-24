#include <iostream>
using namespace std;
int main() {
    char c;
    cin >> c;
    int cortas = 0;
    int medianas = 0;
    int largas = 0;
    bool punto = false;
    while (c != '.') {
        int cont = 0;
        while (c != '-' and not punto) {
            if (c == '.') punto = true;
            if (not punto) {
                ++cont;
                cin >> c;
            }
        }
        if (cont >= 1 and cont < 5) ++cortas;
        else if (cont >= 5 and cont < 10) ++medianas;
        else if (cont >= 10)++largas;
        if (not punto) cin >> c;
    }

    cout << cortas <<',' << medianas << ',' << largas << endl;
}
