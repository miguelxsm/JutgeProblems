#include <iostream>
#include<vector>
#include <queue>
using namespace std;
using Tablero = vector<vector<char>>;
struct Pos {
    int i;
    int j;
};

vector<pair<int,int>> vector_director = {{1,0},{-1,0},{0,-1},{0,1}};

Tablero read_tablero(int n, int m) {
    Tablero t(n,vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
        }
    }
    return t;
}

bool correct_pos(int i, int j, const Tablero& t) {
    return i >= 0 && j >= 0 && i < t.size() && j < t[0].size();
}

priority_queue<int> bfs(const Tablero& t, Pos ini) {
    vector<vector<bool>> visited(t.size(), vector<bool>(t[0].size(), false));
    queue<pair<Pos,int>> q;
    priority_queue<int> res; // donde se almacena las distancias de los tesoros encontrados
    visited[ini.i][ini.j] = true;
    q.push({ini,0});
    while (!q.empty()) {
        Pos act = q.front().first;
        int act_dist = q.front().second;
        q.pop();
        if (t[act.i][act.j] == 't') res.push(act_dist);

        for (pair<int,int> p : vector_director) {
            int i_act = p.first + act.i;
            int j_act = p.second + act.j;
            if (correct_pos(i_act,j_act, t) && !visited[i_act][j_act] && t[i_act][j_act] != 'X') {
                visited[i_act][j_act] = true;
                Pos p; p.i = i_act; p.j = j_act;
                q.push({p,act_dist+1});
            }
        }
    }
    return res;
}

void print(priority_queue<int> q) {
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    Tablero t = read_tablero(n,m);
    Pos ini;
    cin >> ini.i >> ini.j;
    --ini.i; --ini.j;
    priority_queue<int> res = bfs(t,ini);
    if (res.size() > 1) {
        res.pop();
        cout << "second maximum distance: " << res.top();
    }
    else cout << "we cannot reach two or more treasures";
    cout << endl;

}

