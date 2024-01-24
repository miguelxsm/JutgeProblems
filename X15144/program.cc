#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Article {
    string identifier;
    string topic;
    int freq;
};


//pre: n > 0
//post: returns article vector formed by input channel data
vector<Article> initialize_art_vector(int n) {
    vector<Article> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].freq = 0;
        cin >> v[i].identifier >> v[i].topic;
    }
    return v;
}


//pre: v is non-empty
//post: write vector on output
void write_art_vector(const vector<Article>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].topic << ' ' << v[i].freq << ' ' << v[i].identifier << endl;
    }
}

int binary_search(const vector<Article>& v, string s, int izq, int dcha) {
    int n = (izq + dcha) / 2;
    if (s > v[n].identifier) return binary_search(v, s, n + 1, dcha);
    if (s < v[n].identifier) return binary_search(v, s, izq, n - 1);
    else return n;
}

bool cmp(Article& a, Article& b) {
    if (a.topic != b.topic) return a.topic < b.topic;
    if (a.freq != b.freq) return a.freq > b.freq;
    return a.identifier < b.identifier;
}

int main() {
    int n;
    cin >> n;
    vector<Article> v = initialize_art_vector(n);
    string s;
    while (cin >> s) {
        int izq = 0;
        int dcha = n - 1;
        ++v[binary_search(v, s, izq, dcha)].freq;
    }
    sort(v.begin(), v.end(), cmp);
    write_art_vector(v);
}
