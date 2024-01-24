#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<pair<int,bool>>& v, int x) {
    cout << x << " = ";
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) cout << " + ";
        cout << v[i].first;
        if (v[i].second) cout << 'p';
    }
    cout << endl;
}

void backtracking(const vector<int>& list, vector<pair<int,bool>>& coins, int suma, int x, int i) {
    if (suma == x) print_vector(coins,x);
    else {
        for (int k = i; k < list.size(); ++k) {
            if (suma + list[k] <= x) {
                bool segundo = (k % 2 != 0);
                coins.push_back({list[k],segundo});
                backtracking(list, coins, suma+list[k],x,k+1);
                coins.pop_back();
            }
        }
    }
}



int main() {
    int x, n;
    while (cin >> x >> n) {
        vector<int> coins(2*n);
        for (int i = 0; i < 2*n; ++i) {
            int coin;
            cin >> coins[i];
            coins[i+1] = coins[i];
            ++i;
        }
        sort(coins.begin(), coins.end());
        vector<pair<int,bool>> res;
        backtracking(coins, res, 0, x,0);
        cout << "----------" << endl;
    }


}