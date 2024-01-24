#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
using Graph = vector<vector<pair<int,int>>>; // vector< vector<destino,peso>> i -> v[i] => origen = i -> v[i].first con peso v[i].second

struct Nodo {
    int distancia;
    int previo;
    bool visited;
};

//pre: 0 <= s < g.size()
void dijkstra(const Graph& g, int s, vector<Nodo>& v) {

    //preámbulo
    priority_queue< pair<int,int>, vector<pair<int,int > >, greater<pair<int,int>> > q;
    v[s].distancia = 0;
    q.push({0, s}); // se inserta la distancia y el nodo
    //bucle

    while (!q.empty()) {
        int nodo_act = q.top().second;
        q.pop();
        /* Esta condición es esencial ya que es posible que añadamos el mismo nodo con diferente distancia cada vez
        De esta forma solamente se tratará el camino que llega más corto, gracias a la priority_queue */
        if (!v[nodo_act].visited) {
            v[nodo_act].visited = true;
            int dist_actual = v[nodo_act].distancia;
            for (pair<int,int> p : g[nodo_act]) {
                int nodo_mirando = p.first;
                int dist_mirando = p.second;
                if (v[nodo_mirando].distancia > dist_actual + dist_mirando) { // si se cumple actualizamos con nuevos valores
                    v[nodo_mirando].distancia = dist_actual + dist_mirando;
                    v[nodo_mirando].previo = nodo_act;
                    q.push({v[nodo_mirando].distancia, nodo_mirando});
                }
            }
        }
    }
}
//pre: i es el indice del nodo destino
void i_print_path(const vector<Nodo>& v, int i) {
    if (i != -1) {
        i_print_path(v, v[i].previo);
        if (v[i].previo != -1) cout << ' ';
        cout << i;
    }
    
}

//pre: i es el indice del nodo destino, s es el indice del nodo de inicio
void print_path(const vector<Nodo>& v, int i, int s) {
    if (!v[i].visited) cout << "no path from " << s << " to " << i;
    else i_print_path(v, i);
    cout << endl;
}

void Dist(const vector<Nodo>& v, int d) {
    cout << v[d].distancia << endl;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph g(n);
        int origen,destino,peso;
        for (int i = 0; i < m; ++i) {
            cin >> origen >> destino >> peso;
            g[origen].push_back({destino,peso});
        }
        cin >> origen >> destino;
        Nodo N;
        N.distancia = INT_MAX;
        N.previo = -1;
        N.visited = false;
        vector<Nodo> v(n, N);
        dijkstra(g, origen, v);
        print_path(v, destino, origen);
    }
    return 0;
}
