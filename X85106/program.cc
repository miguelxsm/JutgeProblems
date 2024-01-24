#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Binario;
typedef vector<Binario> Matriz;

// Pre: n > 0, m > 0
// Post: retorna una matriz de '0' y '1' con dimensiones n*m leída de la entrada
Matriz leer_matriz(int n, int m) {
    Matriz v(n, Binario(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> v[i][j];
    }
    return v;
}

// Pre: -
// Post: escribe el string s, seguido por dos punts, seguido por el Binario b
void escribir(string s, const Binario& b) {
    cout << s << ":";
    for (int i = 0; i < b.size(); ++i) cout << " " << b[i];
    cout << endl;
}

int pow(int base, int potencia) {
    if (potencia == 0) return 1;
    else {
        return base * pow(base, potencia - 1);
    }
}

int conversor_binario(const Binario& v) {
    int n = 0;
    int j = v.size() - 1;
    for (int i = 0; i < v.size(); ++i) {
        n += int(v[j] - '0')*pow(2, i);
        --j;
    }
    return n;
}

// Pre: gamma.size() = epsilon.size()
// Post: retorna el consumo calculado como gamma*epsilon en decimal
int calcula_consumo(const Binario& gamma, const Binario& epsilon) {
    int consumo;
    consumo = conversor_binario(gamma) * conversor_binario(epsilon);
    return consumo;
}

int sumar_columnas(const Matriz& mat, int j) {
    int suma = 0;
    for (int i = 0; i < mat.size(); ++i) {
        suma += int (mat[i][j] - '0');
    }
    return suma;
}

// Pre: mat.size > 0; gamma.size() == mat[0].size(); epsilon.size() == mat[0].size()
// Post: gamma y epsilon son el ratio gamma y epsilon de mat, respectivamente
void calcula_ratios(const Matriz& mat, Binario& gamma, Binario& epsilon) {
    for (int i = 0; i < gamma.size(); ++i) {
        if (sumar_columnas(mat, i) > double(mat.size() / 2)) gamma[i] = '1';
        else gamma[i] = '0';
    }

    for (int i = 0; i < epsilon.size(); ++i) {
        if (gamma[i] == '1') epsilon[i] = '0';
        else epsilon[i] = '1';
    }
}

int main() {
 int n, m;
    while (cin >> n >> m) {
        Matriz mat = leer_matriz(n, m);
        Binario gamma(m);
        Binario epsilon(m);
        calcula_ratios(mat, gamma, epsilon);
        escribir("Gamma", gamma);
        escribir("Epsilon", epsilon);
        cout << "Consumo: " << calcula_consumo(gamma, epsilon) << endl << endl;
    }
}
