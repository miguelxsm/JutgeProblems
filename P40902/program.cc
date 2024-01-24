#include <iostream>
#include <map>
using namespace std;

void errores(string s, char a) {
    if (a == '1') cout << s << " is already in the casino";
    else if (a == '2') cout << s << " is not in the casino";
    cout << endl;
}

int main() {
    // map (nombre, saldo)

    map<string, int> jugadores;

    string s;
    while (cin >> s) {
        map<string, int>::iterator it = jugadores.find(s);
        string action;
        cin >> action;      
        if (action == "enters") {
            if (it == jugadores.end()) {
                jugadores.insert({s,0});
            }
            else errores(s, '1');
        }

        else if (action == "wins") {
            int x;
            cin >> x;            
            if (it != jugadores.end()) {
                it->second += x;
            }
            else errores(s, '2');
        }

        else if (action == "leaves") {
            if (it != jugadores.end()) {
                cout << s << " has won " << it->second << endl;
                jugadores.erase(it);
            }
            else errores(s, '2');
            
        }
    }

    cout << "----------" << endl;

    if (not jugadores.empty()) {
        map<string, int>::iterator it = jugadores.begin();
        while (it != jugadores.end()) {
            cout << it->first << " is winning " << it->second << endl;
            ++it;
        }
    }

}