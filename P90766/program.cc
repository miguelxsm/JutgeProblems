#include <iostream>
#include <vector>
using namespace std;

using Matriz = vector<vector<char>>;

void print_matrix(const Matriz& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void read_matrix(Matriz& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            cin >> mat[i][j];
        }
    }
}

void is_there_a_treasure(int i, int j, Matriz& mat, int& cont) {
    if (mat[i][j] == 'X') return;
    else if (mat[i][j] == 't' or mat[i][j] == '.') {
        if (mat[i][j] == 't') {
            ++cont;
        }
        mat[i][j] = 'X';
        if (i > 0) is_there_a_treasure(i - 1, j, mat, cont);
        if (i < mat.size() - 1) is_there_a_treasure(i + 1, j, mat, cont);
        if (j > 0) is_there_a_treasure(i, j - 1, mat, cont);
        if (j < mat[0].size() - 1) is_there_a_treasure(i, j + 1, mat, cont);
    }
    

}

int main() {

    int n;
    int m;
    cin >> n >> m;
    Matriz mat(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    read_matrix(mat);
    bool found = false;
    int i, j;
    cin >> i >> j;
    int max_cont = 0;
    is_there_a_treasure(i-1, j-1, mat, max_cont);
    cout << max_cont << endl;
  
}