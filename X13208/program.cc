#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Tablero = vector<vector<int>>;
using Visitados = vector<vector<bool>>;

vector<pair<int,int>> vector_director = {{1,0}, {-1,0}, {0,1}, {0,-1}};

struct Pos {
    int i;
    int j;
    int value;

    bool operator()(const Pos& p, const Pos& p2) {
        return p.value > p2.value;
    }
};

Tablero read_tablero(int n) {
    Tablero t(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> t[i][j];
        } 
    }
    return t;
}

bool borde(const Pos& p, const Tablero& t) {
    return p.i == 0 || p.j == 0 || p.i == t.size() - 1 || p.j == t.size() - 1;
}

int mst(const Tablero& t) {
    Pos ini;
    ini.i = ini.j = t.size()/2;
    ini.value = t[ini.i][ini.j];
    
    Visitados visited(t.size(), vector<bool>(t.size(),false));
    visited[ini.i][ini.j] = true;

    priority_queue<Pos, vector<Pos>, Pos> q;
    q.push(ini);

    while (!q.empty()) {
        Pos act = q.top();
        q.pop();

        if (borde(act,t)) return act.value;

        for (pair<int,int> p : vector_director) {
            Pos mirando;
            mirando.i = act.i + p.first;
            mirando.j = act.j + p.second;
            if (!visited[mirando.i][mirando.j]) {
                mirando.value = act.value + t[mirando.i][mirando.j];
                visited[mirando.i][mirando.j] = true;
                q.push(mirando);
            }
        }
    }
}



int main() {
    int n;
    while (cin >> n) {
        Tablero t = read_tablero(n);
        cout << mst(t) << endl;
    }
}