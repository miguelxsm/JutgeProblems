#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

using Matriz = vector<vector<int>>;
using Visitados = vector<vector<bool>>;

vector<pair<int,int>> sumas = {{1,1}, {-1,-1}, {1,-1}, {-1, 1}};

void read_matrix(Matriz& mat, int& suma, int& huecos) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            string s;
            cin >> s;
            if (s == "X") mat[i][j] = -1;
            else {
                mat[i][j] =  stoi(s);
                suma += mat[i][j];
                ++huecos;
            }
        }
    }
}

bool valid_pos(int i, int j, int n, int m) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

vector<pair<int,int>> comprueba(int i, int j, int n, int m) {
    vector<pair<int,int>> ret;
    for (int k = 0; k < 4; ++k) {
        int i2 = i + sumas[k].first;
        int j2 = j + sumas[k].second;
        if (valid_pos(i2, j2, n, m)) ret.push_back({i2,j2});
    }
    return ret;
}

static void print_vector(const vector<pair<int,int>> v) {
    for (int i = 0; i < v.size(); ++i) {
        printf("(%d, %d)\n", v[i].first, v[i].second);
    }
}

void i_recorrido(const Matriz& mat, Visitados& visitados, int i2, int j2, int& suma, int& huecos) {
    //cout << "Entro a (" << i2 << ", " << j2 << ") con suma = " << suma << " y huecos = " << huecos << endl; 
    if (visitados[i2][j2]) return;
    if (mat[i2][j2] == -1) return;
    else {
        visitados[i2][j2] = true;
        vector<pair<int,int>> v = comprueba(i2, j2, mat.size(), mat[0].size());
        //print_vector(v);
        suma += mat[i2][j2];
        ++huecos;
//--------------------- EN V AHORA SOLAMENTE SE ENCUENTRAN LAS POSICIONES ADYACENTES CON UN ÍNDICE VÁLIDO -----------
        for (int i = 0; i < v.size(); ++i) {
            i_recorrido(mat, visitados, v[i].first, v[i].second, suma, huecos);
            //cout << "vuelvo a (" << i2 << ", " << j2 << ") con suma = " << suma << " y huecos = " << huecos << endl; 
            //print_vector(v);
    }
    }
}

int main() {
    int t; cin >> t;
    for (int z = 0; z < t ; ++z) {
        int n, m;
        cin >> n >> m;
        Matriz mat(n, vector<int>(m));
        Visitados visitados(n, vector<bool>(m,false));
        int suma, huecos;
        suma = huecos = 0;
        read_matrix(mat, suma, huecos);
        if (suma == 0 && huecos == 0) {
            cout << "Case " << z + 1 << ": yes" << endl;
            continue;
        }
        if (suma % huecos != 0) {
            cout << "Case " << z + 1 << ": no" << endl;
            continue;
        }
        int n_iguales = suma / huecos;

//------------- AHORA N_IGUALES CONTIENE LOS ALFILES QUE DEBEN TENER CADA CASILLA CON ALFILES -------------------
        bool b = true;
        for (int i = 0; i < n && b; ++i) {
            for (int j = 0; j < m && b; ++j) {
                if (!visitados[i][j] && mat[i][j] != -1) {
                    int suma, huecos;
                    suma = huecos = 0;
                    i_recorrido(mat, visitados, i, j, suma, huecos);
                    if (suma / huecos != n_iguales) b = false;
                }
            }
        }
        b == 1 ? cout << "Case " << z+1 << ": yes" : cout << "Case " << z+1 << ": no";
        cout << endl; 
    }
}