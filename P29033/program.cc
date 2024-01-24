#include <iostream>
#include <vector>
#include <queue>
#include<set>
using namespace std;
using Graph = vector<vector<int>>;


Graph read_graph(int n, int m) {
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int origen,destino;
        cin >> origen >> destino;
        g[origen].push_back(destino);
        g[destino].push_back(origen);
    }
    return g;
}

bool bfs(const Graph& g, int start, vector<string>& color) {
    queue<int> q;
    color[start] = "red";
    q.push(start);
    while (!q.empty()) {
        int act = q.front();
        q.pop();
        for (int i : g[act]) {
            if (color[i] == "undefined") {
                color[i] = (color[act] == "red" ? "black" : "red");
                q.push(i);
            }
            else if (color[i] == color[act]) return false;
        }
    }
    return true;
}

bool busca(const Graph& g, vector<string>& color) {
    for (int i = 0; i < g.size(); ++i) {
        if (color[i] == "undefined" && !bfs(g,i,color)) return false;
    }
    return true;
}


int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph g = read_graph(n,m);
        vector<string> color(n, "undefined");
        if (busca(g, color)) cout << "yes";
        else cout << "no";
        cout << endl;

        
    }
}