#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Tablero = vector<vector<char>>;
using Visitados = vector<vector<bool>>;

struct Pos {
    int i;
    int j;
    int met_people;
    int n_steps;

    bool operator()(const Pos& p1, const Pos& p2) {
        if (p1.n_steps != p2.n_steps) return p1.n_steps > p2.n_steps;
        return p1.met_people < p2.met_people;
    }
};

vector<pair<int,int>> vector_director = {{1,0}, {-1,0}, {0,1}, {0,-1}};

Tablero read_tablero(int n, int m, Pos& ini) {
    ini.i = ini.j = -1;
    Tablero t(n,vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            t[i][j] = c;
            if (c == 'T') {
                ini.i = i; ini.j = j;
            }
        }
    }
    return t;
}

bool correct_pos(const Pos& p, const Tablero& t) {
    return p.i >= 0 && p.j >= 0 && p.i < t.size() && p.j < t[0].size();
}

pair<int,int> search_telecos(const Tablero& t, Pos ini) {
    Visitados visited(t.size(), vector<bool>(t[0].size(), false));
    visited[ini.i][ini.j] = true;

    priority_queue<Pos, vector<Pos>, Pos> q;

    q.push(ini);

    while (!q.empty()) {
        Pos act = q.top();
        q.pop();

        if (t[act.i][act.j] == 'T') return {act.n_steps, act.met_people};

        for (pair<int,int> p : vector_director) {
            Pos mirando;
            mirando.i = act.i + p.first;
            mirando.j = act.j + p.second;
            if (correct_pos(mirando,t) && !visited[mirando.i][mirando.j] && t[mirando.i][mirando.j] != '#') {
                visited[mirando.i][mirando.j] = true;
                mirando.met_people = act.met_people;
                if (t[mirando.i][mirando.j] == 'P') ++mirando.met_people;
                mirando.n_steps = act.n_steps + 1;
                q.push(mirando);
            }
        }
    }
    return {-1,-1};
}


int main() {
    int n,m;
    while (cin >> n >> m) {
        Pos ini;
        Tablero t = read_tablero(n,m,ini);
        if (ini.i == -1) {
            cout << "The telecos ran away." << endl;
            continue;
        }
        ini.i = ini.j = 0;
        ini.met_people = ini.n_steps = 0;
        if (t[ini.i][ini.j] == 'P') ++ini.met_people;
        pair<int,int> res = search_telecos(t,ini);
        if (res.first == -1) cout << "The telecos is hidden.";
        else cout << res.first << ' ' << res.second;
        cout << endl;
    }
}