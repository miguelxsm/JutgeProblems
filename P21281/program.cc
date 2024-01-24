#include <iostream>
#include <cmath>
using namespace std;

int factor_times(int& aux, int factor) {
    int times = 0;
    while (aux%factor == 0) {
        ++times;
        aux /= factor;
    }
    return times;
}

void factor(int n, int& f, int& q) {
    int i = 2;
    f = n;
    q = 1;
    int times;
    while (i*i <= n) {
        times = factor_times(n, i);
        if (times > q or (times == q and f > i)){
            q = times;
            f = i;
        }
        ++i;
    }
}