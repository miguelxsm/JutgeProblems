#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
using Matriz = vector<vector<char>>;
using Visitados = vector<vector<bool>>;


void read_matrix(Matriz& mat, set<pair<int,int>>& zonas) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            cin >> mat[i][j];
            if (mat[i][j] != '#' && mat[i][j] != '.') {
                zonas.insert({i,j});
            }
        }
    }
}

void print_matrix(const Matriz& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void pintar(Matriz& mat, int i, int j, set<pair<int,int>>& por_visitar, Visitados& visitados, char letra_tratada) {
    if (mat[i][j] == '#') return;
    if (visitados[i][j]) return;
    mat[i][j] = letra_tratada;
    visitados[i][j] = true;
    pintar(mat,i - 1, j, por_visitar, visitados, letra_tratada);
    pintar(mat,i + 1, j, por_visitar, visitados, letra_tratada);
    pintar(mat,i, j - 1, por_visitar, visitados, letra_tratada);
    pintar(mat,i, j + 1, por_visitar, visitados, letra_tratada);
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        set<pair<int,int>> zonas;
        Matriz mat(n, vector<char>(m));
        Visitados visitados(n, vector<bool>(m, false));
        read_matrix(mat, zonas);

//-------AHORA EN EL SET TENGO GUARDADAS LAS POSICIONES QUE CONTENGAN UNA LETRA -----------------

        auto it = zonas.begin();

        while (it != zonas.end()) {
            int i_inicial = it->first;
            int j_inicial = it->second;
            it = zonas.erase(it);
            pintar(mat,i_inicial,j_inicial,zonas,visitados,mat[i_inicial][j_inicial]);
        }

        print_matrix(mat);
        cout << endl;
    }
}