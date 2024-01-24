#include <iostream>
#include <vector>
using namespace std;


bool i_search_decreasing(int x, const vector<int>& v, int e, int d) {
    if (e > d) return false;
    int i = (e+d) / 2;
    if (v[i] < x) return i_search_decreasing(x,v,e,i-1);
    else if (v[i] > x) return i_search_decreasing(x,v,i+1,d);
    else return true;
}

bool i_search(int x, const vector<int>& v, int e, int d)  {
    if (e > d) return false;
    int i = (e+d) / 2;
    if (v[i] < x) return i_search(x,v,i+1,d);
    else if (v[i] > x) return i_search(x,v,e,i-1);
    else return true;
}


int find_i_unimodal(const vector<int>& v, int e, int d) {
    int i = (e+d) / 2;
    if (i > 0 && i < v.size() - 1) {
        if (v[i-1] < v[i] && v[i] > v[i+1]) return i;
        else if (v[i-1] > v[i]) return find_i_unimodal(v,e,i-1);
        else if (v[i+1] > v[i]) return find_i_unimodal(v,i+1,d);
    }
    return i;
}


bool search(int x, const vector<int>& v) {
    int i = find_i_unimodal(v,0,v.size()-1);
    if (v[i] == x) return true;
    return i_search(x,v,0,i-1) or i_search_decreasing(x,v,i+1,v.size()-1);

}

int main() {
    vector<int> v = {1,3,5,7,9,11,13,15,17,16,14,12,10,8,6,4,2,0};
    int n; while (cin >> n) {
    cout << search(n,v) << endl; }
}