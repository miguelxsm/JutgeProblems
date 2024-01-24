#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Map = vector<vector<char>>;
using Visited = vector<vector<bool>>;

vector<pair<int,int>> direcciones = {{1,0}, {-1,0}, {0,1}, {0,-1}};

struct Pos {
    int i;
    int j;
};

bool pos_correct(int n, int m, Pos p) {
    return p.i >= 0 && p.i < n && p.j >= 0 && p.j < m;
}

Map read_map(int n, int m) {
    Map map(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    return map;
}

int bfs(const Map& map, Pos ini) {
    int max_distance = -1;
    queue<pair<Pos,int>> q; // pair<Posicion,Distancia>
    q.push({ini,0});
    int n = map.size(); int m = map[0].size();
    Visited visited(n, vector<bool>(m));
    visited[ini.i][ini.j] = true;
    while (!q.empty()) {
        Pos actual = q.front().first;
        int dist_act = q.front().second;
        q.pop();
        if (map[actual.i][actual.j] == 't') {
            //ha encontrado un tesoro en esta posicion
            if (dist_act > max_distance) max_distance = dist_act;
        }
        for (pair<int,int> p : direcciones) {
            Pos mirando = actual; mirando.i += p.first; mirando.j += p.second;
            if (pos_correct(n,m,mirando) && !visited[mirando.i][mirando.j] && map[mirando.i][mirando.j] != 'X') {
                visited[mirando.i][mirando.j] = true;
                q.push({mirando, dist_act+1});
            }
        }
    }
    return max_distance;
}

int main() {
    int n,m;
    cin >> n >> m;
    Map map = read_map(n,m);
    Pos ini;
    cin >> ini.i >> ini.j;
    ini.i--; ini.j--;
    int max_distance_treasure = bfs(map, ini);
    if (max_distance_treasure != -1) cout << "maximum distance: " << max_distance_treasure;
    else cout << "no treasure can be reached";
    cout << endl;
}