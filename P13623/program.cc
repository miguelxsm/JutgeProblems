#include <iostream>
using namespace std;
int main() {

    int f, c;
    int sumador = 0;
    cin >> f >> c;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                char d;
                cin >> d;
                d = int (d) - '0';
                if (j % 2 == 0 and i % 2 == 0) {
                    sumador += d; 
                }

                else if (j % 2 == 1 and i % 2 == 1) sumador += d;
            }
        }
    
        
            
    cout << sumador << endl;
 }
        
    
    
