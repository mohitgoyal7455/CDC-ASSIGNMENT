#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void nQueenUtil(int col, int n, vector<int> &board,
                vector<bool> &rows, vector<bool> &diag1,
                vector<bool> &diag2, vector<vector<int>> &solutions) {

    if (col > n) {
        solutions.push_back(board);
        return;
    }

    for (int row = 1; row <= n; ++row) {

        if (!rows[row] && !diag1[row + col] && !diag2[row - col + n]) {

            rows[row] = diag1[row + col] = diag2[row - col + n] = true;
            board.push_back(row);

            nQueenUtil(col + 1, n, board, rows, diag1, diag2, solutions);

            board.pop_back();
            rows[row] = diag1[row + col] = diag2[row - col + n] = false;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> solutions;     
    vector<int> board;                

    vector<bool> rows(n + 1, false);   
    vector<bool> diag1(2 * n + 1, false); 
    vector<bool> diag2(2 * n + 1, false);

   
    nQueenUtil(1, n, board, rows, diag1, diag2, solutions);
    return solutions;
}


int main() {
    int n = 4;
    vector<vector<int>> solutions = nQueen(n);

    for (int i = 0; i < solutions.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; ++j) {
            cout << solutions[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }
    return 0;
}
