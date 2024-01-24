#include <iostream>
#include <vector>
using namespace std;

struct Punt {
  double x,y;
};

bool baricentre (const vector<Punt>& v, Punt& b) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].x == b.x and v[i].y == b.y) return false;
    }
    return true;
}

bool propietat1(const vector<Punt>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i].x != v[j].x or v[i].y != v[j].y) return true;
        }
    }
    return false;
}

void propietat2y3(const vector<Punt>& v, bool& propietat2, Punt& b) {
    double sumax = 0;
    double sumay = 0;
    for (int i = 0; i < v.size(); ++i) {
        sumax += v[i].x;
        sumay += v[i].y;
    }
    propietat2 = sumax == sumay;
    b.x = sumax / v.size();
    b.y = sumay / v.size();

}

void leer_puntos(vector<Punt>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    int cantidad;
    while (cin >> cantidad) {
        vector<Punt> v(cantidad);
        leer_puntos(v);
        bool propietat2;
        Punt b;
        propietat2y3(v, propietat2, b);
        cout << "baricentre: (" << b.x << ',' << b.y << ')' << endl;
        if (not propietat1(v)) cout << "el vector no compleix la propietat 1" << endl;
        else if (not propietat2) cout << "el vector no compleix la propietat 2" << endl;
        else if (not baricentre(v, b)) cout << "el vector no compleix la propietat 3" << endl;
        else cout << "vector normalitzat" << endl;
    }

}
