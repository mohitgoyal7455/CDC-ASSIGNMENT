#include <bits/stdc++.c>
using namespace std;

bool isValidMove(const vector<vector<int>>& grid, const vector<vector<bool>>& visited,
                 int row, int col)
{
    int rows = grid.size();
    int cols = grid[0].size();

    return (row >= 0 && row < rows && col >= 0 && col < cols &&
            grid[row][col] == 1 && !visited[row][col]);
}

void exploreLongestRoute(const vector<vector<int>>& grid, vector<vector<bool>>& visited,
                         int r, int c, int destR, int destC,
                         int distance, int& maxDist)
{
    if (grid[r][c] == 0)
        return;

    if (r == destR && c == destC)
    {
        maxDist = max(maxDist, distance);
        return;
    }

    visited[r][c] = true;

    int rowMoves[] = {1, 0, -1, 0};
    int colMoves[] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; dir++)
    {
        int nextR = r + rowMoves[dir];
        int nextC = c + colMoves[dir];

        if (isValidMove(grid, visited, nextR, nextC))
        {
            exploreLongestRoute(grid, visited, nextR, nextC, destR, destC,
                                distance + 1, maxDist);
        }
    }

    visited[r][c] = false;
}

int longestPathLength(vector<vector<int>>& grid, pair<int, int> start,
                      pair<int, int> end)
{
    if (grid.empty() || grid[start.first][start.second] == 0 ||
        grid[end.first][end.second] == 0)
        return -1;

    int rows = grid.size(), cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int maxDist = 0;
    exploreLongestRoute(grid, visited, start.first, start.second,
                        end.first, end.second, 0, maxDist);

    return maxDist;
}

int main()
{
    vector<vector<int>> grid =
    {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> end = {5, 7};

    int result = longestPathLength(grid, start, end);
    cout << "The longest possible path length is: " << result << endl;

    return 0;
}
 