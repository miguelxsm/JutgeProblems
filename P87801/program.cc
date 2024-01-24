#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<char> > Sopa;
typedef vector< vector<int> > Valor;

bool palabra_horizontal(Sopa& sopa_letras, string s, int I, int j) {
    for (int i = 0; i < s.size(); ++i) {
        if (j >= sopa_letras[0].size()) return false;
        if (s[i] != sopa_letras[I][j]) return false;
        ++j;
    }
    return true;
}
bool palabra_vertical(Sopa& sopa_letras, string s, int I, int j2) {
        for (int j = 0; j < s.size(); ++j) {
            if (I >= sopa_letras.size()) return false;
            if (s[j] != sopa_letras[I][j2]) return false;
            ++I;
        }
        return true;
}
int valor(Valor& valores, int tamaño, string direccion, int I, int j) {
    int valor = 0;
    if (direccion == "derecha") {
        int k = 0;
        for (int i = j; k < tamaño; ++i) {
            valor += valores[I][i];
            ++k;
        }
        return valor;

    }
    else {
        int k = 0;
        for (int i = I; k < tamaño; ++i) {
            valor += valores[i][j];
            ++k;
        }
        return valor;
    }

}
void busca_primera_letra(Valor& valores, Sopa& sopa_letras, string s) {
    int valor_maximo = -1;
    bool encontrado = false;
    for (int i = 0; i < valores.size(); ++i) {
        for (int j = 0; j < valores[0].size(); ++j) {
            if (sopa_letras[i][j] == s[0]) {

                if (palabra_horizontal(sopa_letras, s, i, j)) {
                    encontrado = true;

                    int valor_numero = valor(valores, s.size(), "derecha", i, j);

                    if (valor_maximo < valor_numero) valor_maximo = valor_numero;
                }
                if (palabra_vertical(sopa_letras, s, i, j)) {
                    encontrado = true;
                    int valor_numero = valor(valores, s.size(), "abajo", i, j);
                    if (valor_maximo < valor_numero) valor_maximo = valor_numero;
                }
            }
        }
    }
    if (encontrado) cout << valor_maximo << endl;
    else cout << "no" << endl;
}
void leer_sopa(Sopa& sopa_letras) {
    for (int i = 0; i < sopa_letras.size(); ++i) {
        for (int j = 0; j < sopa_letras[0].size(); ++j) cin >> sopa_letras[i][j];
    }
}
void leer_valores(Valor& valores) {
    for (int i = 0; i < valores.size(); ++i) {
        for (int j = 0; j < valores[0].size(); ++j) cin >> valores[i][j];
    }
}
int main() {
    int filas, columnas;
    while (cin >> filas >> columnas) {

            //declaramos y leemos
            Sopa sopa_letras(filas, vector<char>(columnas));
            Valor valores(filas, vector<int> (columnas));
            leer_sopa(sopa_letras);
            leer_valores(valores);

            int cantidad;
            cin >> cantidad;
            for (int i = 0; i < cantidad; ++i) {
                string combinacion;
                cin >> combinacion;
                busca_primera_letra(valores, sopa_letras, combinacion);

            }
    }

}
