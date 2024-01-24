#include <iostream>
#include <vector>
using namespace std;


struct Alumne {
    int dni;
    string nom;
};


struct Nota {
    int dni;
    string ass;     // assignatura
    string fac;     // facultat
    double nota;
};


void llegeix_alumnes(vector<Alumne>& alumnes) {
    int m;
    cin >> m;
    alumnes = vector<Alumne>(m);
    for (int i = 0; i < m; ++i) cin >> alumnes[i].dni >> alumnes[i].nom;
}


void llegeix_notes(vector<Nota>& notes) {
    int n;
    cin >> n;
    notes = vector<Nota>(n);
    for (int i = 0; i < n; ++i) {
        cin >> notes[i].dni >> notes[i].ass >> notes[i].fac >> notes[i].nota;
    }
}


int dichotomic_search(const vector<Alumne>& v, int s, int izq, int dcha) {
    int n = (izq + dcha) / 2;
    if (izq > dcha) return -1;
    if (v[n].dni > s) return dichotomic_search(v, s, izq, n - 1);
    if (v[n].dni < s) return dichotomic_search(v, s, n + 1, dcha);
    else return n;
}

int main() {
    cout.setf(ios::fixed);      // estableix el format dels reals
    cout.precision(2);          // per escriure les notes

    vector<Alumne> alumnes;
    vector<Nota> notes;
    llegeix_alumnes(alumnes);
    llegeix_notes(notes);

    for (int i = 0; i < notes.size(); ++i) {
        int izq = 0;
        int dcha = alumnes.size() - 1;
        int pos = dichotomic_search(alumnes, notes[i].dni, izq, dcha);
        if (pos != -1) {
            cout << alumnes[pos].dni << ' ' << alumnes[pos].nom << endl;
            double suma = 0;
            double num = 0;
            for (int j = i; j < notes.size() and notes[j].dni == alumnes[pos].dni; ++j) {
                ++num;
                suma += notes[j].nota;
                i = j;
                cout << "     " << notes[j].ass << ' ' << notes[j].fac << ' ' << notes[j].nota << endl;
            }
            cout << "     mitjana: " << double(suma / num) << endl;
            cout << endl;
        }

        }
}
