#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Graph = vector<vector<int>>;

void read_graph(Graph& g, int m, vector<int>& degrees, priority_queue<int, vector<int>, greater<int>>& q) {
    for (int i = 0; i < m; ++i) {
        int r,c;
        cin >> r >> c;
        g[r].push_back(c);
        degrees[c]++;
    }

    for (int i = 0; i < degrees.size(); ++i) {
        if (degrees[i] == 0) q.push(i);
    }

}

void topological_sort(const Graph& g, vector<int>& degrees, priority_queue<int, vector<int>, greater<int>>& q) {
    bool primero = true;
    while (!q.empty()) {
        if (!primero) {
            cout << ' '; 

        }
        int n = q.top();
        q.pop();
        for (int i : g[n]) {
            if (--degrees[i] == 0) q.push(i);
        }
        cout << n;
        primero = false;
    }
}

int main() {

    int n,m;
    while (cin >> n >> m) {
        Graph g(n);
        vector<int> degrees(n, 0);
        priority_queue<int, vector<int>, greater<int>> q;
        read_graph(g, m, degrees, q);
        topological_sort(g,degrees, q);
        cout << endl;

    }
}