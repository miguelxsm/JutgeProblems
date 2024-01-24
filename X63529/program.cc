#include <iostream>
using namespace std;
int main() {
    int hora, minuto, retraso;
    cin >> hora >> minuto >> retraso;
    int hora_nueva = 0;
    int minuto_nuevo;
    minuto_nuevo = minuto + retraso;

    while (minuto_nuevo > 59) {
        minuto_nuevo -= 60;
        ++hora;
    }
    hora_nueva += hora;
    while (hora_nueva > 23) hora_nueva -= 24;


    if (hora_nueva < 10) cout << '0';
    cout << hora_nueva << ':';
    if (minuto_nuevo < 10) cout << '0';
    cout << minuto_nuevo << endl;

}
