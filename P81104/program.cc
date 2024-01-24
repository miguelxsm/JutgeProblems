#include <iostream>
#include <vector>
using namespace std;

struct Assignatura {
    string nom;                 // Nom de l’assignatura
    double nota;                // Entre 0 i 10, -1 indica NP
};

struct Alumne {
    string nom;                 // Nom de l’alumne
    int dni;                    // DNI de l’alumne
    vector<Assignatura> ass;    // Llista d’assignatures de l’alumne
};



double nota(const vector<Alumne>& alums, int dni, string nom) {
    for (int i = 0; i < alums.size(); ++i) {
        if (alums[i].dni == dni) {
            for (int j = 0; j < alums[i].ass.size(); ++j) {
                if (alums[i].ass[j].nom == nom) return alums[i].ass[j].nota;
            }
            return -1;
        }
    }
    return -1;
}

double mitjana(const vector<Assignatura>& ass) {
    int n = ass.size();
    double suma = 0;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        if (ass[i].nota != -1) {
            suma += ass[i].nota;
            ++num;
        }
    }
    if (num != 0) return double(suma / num);
    else return -1;
}

void compta(const vector<Alumne>& alums, int dni, string nom, int& com) {
    double nota_comparar = nota(alums, dni, nom);
    for (int i = 0; i < alums.size(); ++i) {
        if (mitjana(alums[i].ass) > nota_comparar) ++com;
    }

}

void lee_vector(vector<Alumne>& v) {
    for (int i = 0; i < v.size(); ++i) {
        int n;
        cin >> v[i].nom >> v[i].dni >> n;
        vector<Assignatura> w(n);
        for (int j = 0; j < n; ++j) cin >> w[j].nom >> w[j].nota;
        v[i].ass = w;
    }
}

int main() {
    int cantidad;
    cin >> cantidad;
    vector<Alumne> v(cantidad);
    lee_vector(v);
    int dni;
    string asignatura;


    while (cin >> dni >> asignatura) {
        int com = 0;
        compta(v, dni, asignatura, com);
        cout << com << endl;
    }

}
