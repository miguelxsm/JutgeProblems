#include <vector>
#include <iostream>
using namespace std;


int i_first_ocurrence(double x, const vector<double>& v, int e, int d, int& max_pos) {
    int m = (e + d) / 2;
    if (e > d) return -1;
    else if (v[m] < x) {
        if (m > max_pos) max_pos = m;
        return i_first_ocurrence(x,v,m+1,d, max_pos);
    }
    else if (v[m] > x) return i_first_ocurrence(x,v,e,m - 1, max_pos);
    else return m;
}

int first_occurrence(double x, const vector<double>& v) {
    int pos = v.size();
    int max_pos = 0;
    int pos2 = -1;
    if (v.empty()) return -1;
    while (pos != -1) {
        pos = i_first_ocurrence(x,v,max_pos,pos-1, max_pos);
        if (pos != -1 && v[pos] == x) pos2 = pos;
    }
    return pos2;
}

int main() {
    vector<double> v;
    double x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        v.push_back(x);
    }
    cin >> x;
    cout << first_occurrence(x, v) << endl;
}