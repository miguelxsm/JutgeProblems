#include <iostream>
#include <queue>
using namespace std;

int main() {
    char a;
    priority_queue<int> pq;
    
    while (cin >> a) {

        if (a == 'A') {
            if (not pq.empty()) cout << pq.top();
            else cout << "error!";
            cout << endl;
        }

        else if (a == 'S') {
            int x;
            cin >> x;
            pq.push(x);
        }

        else if (a == 'R') {
            if (not pq.empty()) pq.pop();
            else cout << "error!" << endl;
        }

        else if (a == 'I') {
            int x;
            cin >> x;
            if (not pq.empty()) {
                int aux = pq.top();
                aux += x;
                pq.pop();
                pq.push(aux);
            }

            else cout << "error!" << endl;
        }

        else if (a == 'D') {
            int x;
            cin >> x;
            if (not pq.empty()) {
                int aux = pq.top();
                aux -= x;
                pq.pop();
                pq.push(aux);
            }
            else cout << "error!" << endl;
        }
    }
}