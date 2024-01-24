#include <iostream>
#include <vector>
using namespace std;
using Sudoku = vector<vector<int>>;

Sudoku read_sudoku(int n) {
    Sudoku s(n, vector<int>(n,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            if (c != '.') s[i][j] = c - '0';
        }
    }
    return s;
}

void write_sudoku(const Sudoku& s) {
    for (int i = 0; i < s.size(); ++i) {
        bool primero = true;
        for (int j = 0; j < s.size(); ++j) {
            if (!primero) cout << ' ';
            cout << s[i][j];
            primero = false;
        }
        cout << endl;
    }
}

bool check_cols(const Sudoku& s, int col, int n) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i][col] == n) return false;
    }
    return true;
}

bool check_rows(const Sudoku& s, int row, int n) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[row][i] == n) return false;
    }
    return true;
}

bool check_subsquare(const Sudoku& s, int i, int j, int n) {
    int I = (i/3) * 3;
    int J = (j/3) * 3;
    for (i = I; i < I + 3; ++i) {
        for (j = J; j < J + 3; ++j) {
            if (s[i][j] == n) return false;
        }
    }
    return true;    
}

bool valid_pos(const Sudoku& s, int i, int j, int n) {
    return check_cols(s,j,n) && check_rows(s,i,n) && check_subsquare(s,i,j,n);
}

void solve(Sudoku& s, int i, int j, bool& solved) {
    // Caso base: si hemos llegado al final de las filas, hemos terminado
    if (solved) return;
    
    else if (i == 9) {
        solved = true;
        cout << endl;
        write_sudoku(s);
        return;
    }

    // Si hemos llegado al final de una fila, pasamos a la siguiente
    else if (j == 9) {
        solve(s, i + 1, 0, solved);
        return;
    }

    // Si la celda actual ya está llena, pasar a la siguiente celda
    else if (s[i][j] != 0) {
        solve(s, i, j + 1, solved);
    } else {
        // Intentar colocar un número del 1 al 9
        for (int k = 1; k <= 9; ++k) {
            if (valid_pos(s, i, j, k)) {
                s[i][j] = k;
                solve(s, i, j + 1, solved);
                s[i][j] = 0;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        Sudoku s = read_sudoku(9);
        bool solved = false;
        solve(s,0,0, solved);
        
    }
}