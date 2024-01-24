#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct Nodo {
    char c; // valor
    int dist; // distancia minima
    pair<int,int> pred;
    bool visitado;
};

using Matriz = vector<vector<Nodo>>;

vector<pair<int,int>> sumas = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

vector<pair<int,int>> comprueba(int i, int j) {
    vector<pair<int,int>> res = sumas;
    for (int k = 0; k < 4; ++k) {
        res[k].first+= i; res[k].second+=j;
    }
    return res;
}

bool legit_par(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void read_matrix(Matriz& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            cin >> mat[i][j].c;
        }
    }
}

void pint_struct(const Nodo& n) {

}

void bfs(Matriz& mat, int i, int j, int& min_dist) {
    queue<pair<int,int>> q;
    q.push({i,j});

    while (!q.empty()) {
        pair<int,int> act = q.front();
        q.pop();
        if (mat[act.first][act.second].c == 't') {
            min_dist = min(min_dist, mat[act.first][act.second].dist);  
        }      
        vector<pair<int,int>> adyacentes = comprueba(act.first, act.second);
        for (pair<int,int> k : adyacentes) {
            if (legit_par(k.first,k.second, mat.size(), mat[0].size()) && mat[k.first][k.second].c != 'X') {
                int d = mat[act.first][act.second].dist; int d_ady = mat[k.first][k.second].dist;
                if (d + 1 < d_ady) {
                    mat[k.first][k.second].dist = d + 1;
                    mat[k.first][k.second].pred = {act.first, act.second};
                    mat[k.first][k.second].visitado = true;
                    q.push({k.first, k.second});
                }
            }
        }
    }


}


int main() {
    int n, m;
    cin >> n >> m;
    Nodo no;
    no.c = '0';
    no.dist = n*m;
    no.pred = {-1,-1};
    no.visitado = false;
    Matriz mat(n,vector<Nodo>(m, no));
    read_matrix(mat);
    int distancia_minima = n*m;

    int i,j;
    cin >> i >> j;
    mat[--i][--j].dist = 0;
    mat[i][j].visitado = true;
    bfs(mat,i,j,distancia_minima);
    
    distancia_minima == n*m ? cout << "no treasure can be reached" << endl : cout << "minimum distance: " << distancia_minima << endl;
    

}