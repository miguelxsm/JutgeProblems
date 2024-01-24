#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<pair<int,int>>>;
using Arista = pair<int,int>; // peso,nodo

Graph read_graph(int n, int m) {
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int o,d,p;
        cin >> o >> d >> p;
        --o; --d;
        g[o].push_back({d,p});
        g[d].push_back({o,p});
    }
    return g;
}

int prim(const Graph& g, int start) {
    priority_queue<Arista, vector<Arista>, greater<Arista>> q;
    vector<bool> visited(g.size(), false);
    q.push({0,start});
    int c = 0;
    while (!q.empty()) {
        int peso = q.top().first;
        int nodo = q.top().second;
        q.pop();
        if (!visited[nodo]) {
            c += peso;
            visited[nodo] = true;
            for (auto p : g[nodo]) {
                q.push({p.second, p.first});
            }
        }        
    }
    return c;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph g = read_graph(n,m);
        cout << prim(g, 0) << endl;
    }
}