#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Tablero = vector<vector<char>>;
using Visited = vector<vector<bool>>;


vector<pair<int,int>> vector_director = {{2,1}, {-2,1}, {2, -1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};

struct Pos{
    int i;
    int j;
};

bool correct_pos(const Pos& p, const Tablero& t) {
    return p.i >= 0 && p.i < t.size() && p.j >= 0 && p.j < t[0].size();
}

Tablero read(int n, int m, Pos& ini) {
    Tablero t(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            t[i][j] = c;
            if (c == 'C') {
                ini.i = i;
                ini.j = j;
            }
        } 
    }
    return t;
}

void bfs(const Tablero& t, Pos ini) {
    cout.setf(ios::fixed);
    cout.precision(4);
    Visited visited(t.size(), vector<bool>(t[0].size(), false));
    queue<pair<Pos,int>> q; // cola de <posiciones, pasos necesarios para esa posicion>
    visited[ini.i][ini.j] = true;
    q.push({ini,0});
    int flors = 0;
    double pasos = 0;

    //bfs
    while (!q.empty()) {
        int dist_act = q.front().second;
        Pos act = q.front().first;
        q.pop();
        if (t[act.i][act.j] == 'F') {
            ++flors;
            pasos += dist_act;
        }

        for (pair<int,int> p : vector_director) {
            Pos mirando;
            mirando.i = act.i + p.first;
            mirando.j = act.j + p.second;
            if (correct_pos(mirando,t) && !visited[mirando.i][mirando.j] && t[mirando.i][mirando.j] != 'a') {
                visited[mirando.i][mirando.j] = true;
                q.push({mirando, dist_act+1});
            }
        }
    }
    if (flors == 0) cout << "el cavall no pot arribar a cap flor" << endl;
    else {
        double d = (pasos/flors);
        cout << "flors accessibles: " << flors << endl << "distancia mitjana: " << d << endl;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    Pos ini;
    Tablero t = read(n,m,ini);
    bfs(t,ini);
}
