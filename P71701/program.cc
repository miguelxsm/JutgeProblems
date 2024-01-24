#include <iostream>
#include <vector>
using namespace std;
using Tablero = vector<vector<char>>;

vector<pair<int,int>> vector_director = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};

void escribir_tablero(const Tablero& t) {
    for (int i = 0; i < int(t.size()); ++i) {
        for (int j = 0; j < int(t.size()); ++j) {
            cout << t[i][j];
        }
        cout << endl;
    }
}

bool pos_correcta(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool safe_pos(const Tablero& t, int i, int j) {
    for (pair<int,int> p : vector_director) {
        int i_mirando = p.first + i;
        int j_mirando = p.second + j;
        if (pos_correcta(i_mirando,j_mirando,int(t.size())) && t[i_mirando][j_mirando] == 'K') return false;
    }
    return true;
}

void r_reis(Tablero& t, int r, int i, int j) {
    if (r == 0) {
        escribir_tablero(t);
        cout << "----------" << endl;
    }
    else if (i == int(t.size())) return;
    else if (j == int(t.size())) r_reis(t,r,i+1,0);

    else {
        if (safe_pos(t,i,j)) {
            t[i][j] = 'K';
            --r;
            r_reis(t,r,i,j+1);
            ++r;
            t[i][j] = '.';
        }
        r_reis(t,r,i,j+1);

    }
}





int main() {
    int n,r;
    cin >> n >> r;
    Tablero t(n, vector<char>(n,'.'));
    r_reis(t,r,0,0);

}