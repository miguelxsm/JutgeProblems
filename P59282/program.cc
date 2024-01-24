#include <iostream>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;

int main(){
    int max = INT_MIN;
    int suma = 0;
    int cont = 0;
    string s;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (cin >> s) {       
        if (s == "delete") {
            if (pq.empty()) {
                cout << "no elements" << endl;
                
            }
            else {
                suma -= pq.top();
                --cont;
                pq.pop();
                cout.setf(ios::fixed);
                if (not pq.empty()) cout << "minimum: " << pq.top() << ", maximum: " << max << ", average: " << setprecision(4) << double(suma)/cont << endl;
                else {
                cout << "no elements" << endl;
                max = INT_MIN;
                }

            }
        }
        else {
            int x;
            cin >> x;
            pq.push(x);
            suma += x;
            ++cont;
            if (x > max) max = x;
            cout.setf(ios::fixed);
            cout << "minimum: " << pq.top() << ", maximum: " << max << ", average: " << setprecision(4) << double(suma)/cont << endl;

        }

    }

}