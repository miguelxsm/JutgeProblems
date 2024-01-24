#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title;       // título del libro
    int nb_pag;         // número de páginas del libro
};

struct Author {
    string name;        // nombre del autor
    Book bestseller;    // libro superventas
};

typedef vector<Author> Library;
// (...)

Library read_data() {
    int cantidad;
    cin >> cantidad;
    Library v(cantidad);
    for (int i = 0; i < cantidad; ++i) {
        cin >> v[i].name >> v[i].bestseller.title >> v[i].bestseller.nb_pag;
    }
    return v;
}

// escribe el nombre de un actor en funcion de p y de c dada en la funcion main;
void print_author(const Library& v, int p, char c) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i].bestseller.title[0] == c and v[i].bestseller.nb_pag > p) cout << v[i].name << endl;
    }
}

int main() {
    Library v = read_data();
    char c;
    int p;
    while (cin >> c >> p) {
        cout << "-- begin query" << endl;
        print_author(v, p, c);
        cout << "-- end query" << endl;
    }
}
