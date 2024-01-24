#include <iostream>
#include <vector>
using namespace std;

//pre: entran dos valores, un patron y una palabra
//
//post: sale si cumple las condiciones descritas por el problema

bool pattern_match(string patron, string s) {
    for (int i = 0; patron[i] != '*'; ++i) {
        if (patron[i] != s[i]) return false;
    }

    int pos_s = s.size() - 1;
    for (int i = patron.size() - 1; patron[i] != '*'; --i) {
        if (patron[i] != s[pos_s]) return false;
        --pos_s;
    }
    return true;
}

int main() {
    string patron;
    while (cin >> patron) {
        int cantidad;
        cin >> cantidad;
        vector <string> v(cantidad);
        cout << patron << ':' << endl;
        for (int i = 0; i < cantidad; ++i) {
            cin >> v[i];
            if (v[i].size() < patron.size() - 1) continue;
            if (pattern_match(patron, v[i])) cout << "    " << v[i] << endl;
        }
    }

}
