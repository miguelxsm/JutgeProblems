#include <iostream>
#include <map>
using namespace std;


struct Info {
  string code;
  int price;
};


int main() {
  map<int, Info> M;
  char c;
  while (cin >> c) {
    if (c == 'n') {
      cout << "num: " << M.size() << endl;
    }
    else if (c == 'u') {
      string code;
      int length, price;
      cin >> code >> length >> price;
      Info I;
        I.code = code;
        I.price = price;
        auto it = M.find(length);
        if (it == M.end()) M.insert({length,I});
        else it->second = I;
    }
    else if (c == 'q') {
      int length;
      cin >> length;
      if (M.find(length) == M.end()) cout << -1;
      else cout << M[length].price;
      cout << endl;
    }
    else if (c == 'p') {
      cout << string(10, '-') << endl;
      for (auto m : M) {
        cout << m.second.code << ' ' << m.first << ' ' << m.second.price << endl;
      }
      cout << string(10, '*') << endl;
    }
    else { // c == 's'
      if (M.size() < 2) cout << "no" << endl;
      else {
        auto it = M.begin();
        ++it;
        cout << it->second.code << ' ' << it->first << ' ' << it->second.price << endl;
      }
    }
  }
}
