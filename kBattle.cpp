#include <bits/stdc++.h>
using namespace std;

struct Ship {
    int rowAttack;
    int columnAttack;
    int diagonalAttack;
};

class BattleshipPlacement {
private:
    int N, M, K;
    vector<Ship> ships;
    vector<pair<int, int>> placement; 
    
    bool attacks(int shipIdx, int row, int col, int r, int c) {
        Ship& ship = ships[shipIdx];
        
        if (row == r && col == c) return true;
        
        if (row == r) {
            int dist = abs(col - c);
            if (dist <= ship.rowAttack) return true;
        }
        
        if (col == c) {
            int dist = abs(row - r);
            if (dist <= ship.columnAttack) return true;
        }
        
        int rowDiff = abs(row - r);
        int colDiff = abs(col - c);
        if (rowDiff == colDiff && rowDiff <= ship.diagonalAttack) {
            return true;
        }
        
        return false;
    }
    
    bool isSafe(int shipIdx, int row, int col) {
        for (int i = 0; i < placement.size(); i++) {
            int placedRow = placement[i].first;
            int placedCol = placement[i].second;
            
            if (attacks(shipIdx, row, col, placedRow, placedCol)) {
                return false;
            }
            
            if (attacks(i, placedRow, placedCol, row, col)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool solve(int shipIdx) {
        if (shipIdx == K) {
            return true;
        }
        
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (isSafe(shipIdx, row, col)) {
                    placement.push_back({row, col});
                    
                    if (solve(shipIdx + 1)) {
                        return true;
                    }
                    
                    placement.pop_back();
                }
            }
        }
        
        return false;
    }
    
public:
    BattleshipPlacement(int n, int m, int k, vector<Ship>& s) 
        : N(n), M(m), K(k), ships(s) {}
    
    bool canPlaceShips() {
        placement.clear();
        return solve(0);
    }
    
    vector<pair<int, int>> getPlacement() {
        return placement;
    }
    
    void printPlacement() {
        if (placement.empty()) {
            cout << "No valid placement found!\n";
            return;
        }
        
        cout << "Valid placement found:\n";
        for (int i = 0; i < K; i++) {
            cout << "Ship " << i + 1 << " at position (" 
                 << placement[i].first << ", " << placement[i].second << ")\n";
        }
        
        cout << "\nBoard visualization:\n";
        vector<vector<int>> board(N, vector<int>(M, 0));
        for (int i = 0; i < K; i++) {
            board[placement[i].first][placement[i].second] = i + 1;
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) {
                    cout << ". ";
                } else {
                    cout << board[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    cout << "=== Test Case 1 ===\n";
    {
        int N = 5, M = 5, K = 2;
        vector<Ship> ships = {
            {1, 1, 1}, 
            {1, 1, 1}  
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships!\n";
        }
    }
    
    cout << "\n=== Test Case 2 ===\n";
    {
        int N = 4, M = 4, K = 3;
        vector<Ship> ships = {
            {2, 1, 1},  
            {1, 2, 1}, 
            {1, 1, 2}   
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships!\n";
        }
    }
    
    cout << "\n=== Test Case 3: Impossible case ===\n";
    {
        int N = 3, M = 3, K = 3;
        vector<Ship> ships = {
            {5, 5, 5},  
            {5, 5, 5},
            {5, 5, 5}
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships! (Attack ranges too large)\n";
        }
    }
    
    cout << "\n=== Test Case 4: Example from problem ===\n";
    {
        int N = 10, M = 10, K = 2;
        vector<Ship> ships = {
            {3, 3, 2},  
            {2, 2, 2}
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships!\n";
        }
    }
    
    return 0;
}