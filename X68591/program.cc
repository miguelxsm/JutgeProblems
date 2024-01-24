#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
using Visited = vector<bool>;

Graph read_graph(int n, int m) {
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int r,c;
        cin >> r >> c;
        g[r].push_back(c);
        g[c].push_back(r);
    }
    return g;
}

void dfs(const Graph& g, Visited& visited, int n, int& nodes) {
    for (int x : g[n]) {
        if (!visited[x]) {
            visited[x] = true;
            nodes++;
            dfs(g,visited,x, nodes);
        }
    }
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph g = read_graph(n,m);
        Visited visited(n,false);
        int max_n = 0;
        int min_n = n+1;
        for (int i = 0; i < n; ++i) {
            int nodes = 0;
            if (!visited[i]) {
                dfs(g,visited,i,nodes);
                nodes == 0 ? nodes = 1 : nodes = nodes;
                max_n = max(max_n,nodes);
                min_n = min(min_n,nodes);
            }
        }
        cout << min_n << ' ' << max_n << endl;
    }
}