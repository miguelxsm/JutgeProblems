#include <iostream>
using namespace std;
int main() {
    int n, m;
    int sim_seq = 1;

        // suma de la primera secuencia y ultimo numero
        int ultimo1;
        int suma1 = 0;
        cin >> n;
        while (n != 0) {
            ultimo1 = n;
            suma1 += ultimo1;
            cin >> n;
        }
    int suma2 = 1;
    while (suma2 != 0) { // si la suma de la segunda secuencia es 0 sale del bucle (secuencia vacía)
    //suma del resto de secuencias y los ultimos numeros
    int ultimo2;
    suma2 = 0;
    cin >> m;
        while (m != 0) {
            ultimo2 = m;
            suma2 += ultimo2;
            cin >> m;
        }
        if (suma1 == suma2 and ultimo1 == ultimo2) ++sim_seq;
    }

    cout << sim_seq << endl;
}
