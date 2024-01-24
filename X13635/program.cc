#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
  string artist, title, genre;
  int year;
};


vector<Track> read_tracks(int n) {
    vector<Track> v(n);
     for (int i = 0; i < n; ++i) {
         cin >> v[i].artist >> v[i].title >> v[i].genre >> v[i].year;
      }
      return v;
}

void print_track(const Track &t) {
  cout << t.artist;
  cout << " (" << t.year;
  cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

bool comparar(Track& a, Track& b) {
    if (a.artist != b.artist) return a.artist < b.artist;
    if (a.year != b.year) return a.year < b.year;
    return a.title < b.title;
}

int main() {
  int cantidad;
  cin >> cantidad;
  vector<Track> v = read_tracks(cantidad);
  string s;
  while (cin >> s) {
      vector<Track> w(0);
      for (int i = 0; i < v.size(); ++i) if (v[i].genre == s) w.push_back(v[i]);
      sort(w.begin(), w.end(), comparar);
      for (int i = 0; i < w.size(); ++i) print_track(w[i]);
     }
}
