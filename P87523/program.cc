#include<iostream>
using namespace std;
int main(){

    char entrada;
    cin >> entrada;
    bool found = false;
    char h = ' ';
    char o = ' ';
    char l = ' ';
    char a = entrada;

    while (entrada != '.'){
    cin >> entrada;
    h = o;
    o = l;
    l = a;
    a = entrada;
    if ((h == 'h') and (o == 'o') and (l == 'l') and (a == 'a')) found = true;

    }

    if (found) cout << "hola" << endl;
    else cout << "adeu" << endl;
}
