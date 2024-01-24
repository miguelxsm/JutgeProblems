#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int evaluate(const vector<int>& p, int x) {
    int resultado = 0;
    for(int i = 0; i < p.size(); ++i) {
        resultado += pow(x, i) * p[i];
    }
    return resultado;
}
