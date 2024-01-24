#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Tablero = vector<vector<char>>;
using Visitados = vector<vector<bool>>;


vector<pair<int,int>> vector_director = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

Tablero read_tablero(int n, int m, int& i_ini, int& j_ini) {
    Tablero t(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; 
            cin >> c;
            t[i][j] = c;
            if (c == 'P') {
                i_ini = i;
                j_ini = j;
            }
        }
    }
    return t;
}



bool hay_fantasma_adyacente(const Tablero& t, int i, int j) {
    for (pair<int,int> p : vector_director) {
        int i_mirando = i + p.first;
        int j_mirando = j + p.second;
        if (t[i_mirando][j_mirando] == 'F') return true;
    }
    return false;
}

bool bfs(const Tablero& t, int i_ini, int j_ini) {
    Visitados visited(t.size(), vector<bool>(t[0].size(),false));
    visited[i_ini][j_ini] = true;

    queue<pair<int,int>> q;
    q.push({i_ini, j_ini});
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (!hay_fantasma_adyacente(t,i,j) && t[i][j] == 'B') return true;

        for (int k = 0; k < 4; ++k) {
            int i_mirando = i + vector_director[k].first;
            int j_mirando = j + vector_director[k].second;
            if (!visited[i_mirando][j_mirando] && t[i_mirando][j_mirando] != 'X' && !hay_fantasma_adyacente(t,i_mirando,j_mirando)) {
                visited[i_mirando][j_mirando] = true;
                q.push({i_mirando,j_mirando});
            }
        }
    }
    return false;
}

int main() {
    int n, m, i, j; // i y j son las posiciones de inicio del pacman
    
    while (cin >> n >> m) {
        Tablero t = read_tablero(n,m,i,j);
        Visitados visited(n, vector<bool>(m,false));
        if (!hay_fantasma_adyacente(t,i,j) && bfs(t,i,j)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}
