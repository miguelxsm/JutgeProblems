#include <iostream>
#include <map>
using namespace std;

int main() {
    char opcion;
    map<string, int> m;
    while (cin >> opcion) {
        string s; cin >> s;
        map<string, int>::iterator it = m.find(s);
        if (it == m.end()) {
            m.insert(make_pair(s,0));
            it = m.find(s);
        }
        
        if (opcion == 'a') {
            it->second++;
        }
        else cout << it->second << endl;
    }
}