#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int>>;

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

struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
    }
};


int bfs(const Graph& g) {
    int ini = 0;
    vector<bool> visited(g.size(),false);
    queue<pair<int,int>> q; // queue of bfs
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> qdists; //queue of distances, vertex
    visited[0] = true;
    q.push({0,0});
    while (!q.empty()) {
        int act = q.front().first;
        int act_dist = q.front().second;
        q.pop();
        qdists.push({act_dist,act});
    
        for (int i : g[act]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push({i,act_dist+1});
            }
        }
    }
    return qdists.top().second;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph g = read_graph(n,m);
        cout << bfs(g) << endl;
    }
}