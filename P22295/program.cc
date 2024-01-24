#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<char>>;
using Visited = vector<vector<bool>>;

vector<pair<int,int>> vector_director = {{0,1}, {0,-1}, {1,0}, {-1,0}};

Matrix read_matrix(int n, int m) {
    Matrix mat(n,vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    return mat;
}

bool pos_correct(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(const Matrix& mat, int i, int j, int i_fi, int j_fi, string res, Visited& visited) {
    if (i == i_fi && j == j_fi) {
        res += mat[i][j];
        cout << res << endl;
    }
    else {
        for (pair<int,int> p : vector_director) {
            int i_mirando = i + p.first;
            int j_mirando = j + p.second;
            if (pos_correct(i_mirando,j_mirando,mat.size(),mat[0].size()) && !visited[i_mirando][j_mirando]) {
                visited[i_mirando][j_mirando] = true;
                dfs(mat,i_mirando,j_mirando,i_fi,j_fi,res+mat[i][j],visited);
                visited[i_mirando][j_mirando] = false;
            }

        }
    }

}

int main() {
    int n,m;
    cin >> n >> m;
    Matrix mat = read_matrix(n,m);
    Visited visited(n,vector<bool>(m,false));
    int i_ini, i_fi,j_ini,j_fi;
    cin >> i_ini >> j_ini >> i_fi >> j_fi;
    visited[i_ini][j_ini] = true;
    dfs(mat,i_ini,j_ini,i_fi,j_fi,"",visited);
}