#include <iostream>
#include <vector>
#include <set>
using namespace std;

using Graph = vector<vector<int>>;
using Visitados = vector<bool>;


void read_graph(Graph& g, int m) {
    for (int i = 0; i < m; ++i) {
        int r,c;
        cin >> r >> c;
        g[r].push_back(c);
        g[c].push_back(r);
    }
}

void i_ciclos(const Graph& g, Visitados& visitados, bool& b, int n, int antecesor) {
    if (!visitados[n]) {
        visitados[n] = true;
        for (int i = 0; i < g[n].size(); ++i) {
            if (g[n][i] != antecesor) {
                i_ciclos(g,visitados,b,g[n][i], n);
            }
        }
    }
    else {
        b = true;
        return;
    }
}

int ciclos(const Graph& g, Visitados& visitados) {
    int narbres = 0;
    bool ciclos = false;
    for (int i = 0; i < g.size(); ++i) {
        if (!visitados[i]) {
            i_ciclos(g,visitados,ciclos, i, -1);
            if (ciclos) return -1;
            ++narbres;
        }
    }
    return narbres;
}



int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph g(n);
        Visitados visitados(n, false);
        read_graph(g, m);
        if (m == 0) {
            cout << n << endl;
            continue;
        }
        int qt = ciclos(g,visitados);
        qt == -1 ? cout << "no" : cout << qt;
        cout << endl;
    }
}