#include <iostream>
#include <vector>
using namespace std;


bool isSafe(int row, int col, int N) {
    return (row >= 0 && col >= 0 && row < N && col < N);
}

void explorePaths(const vector<vector<int>>& maze,
                  int r, int c,
                  pair<int, int>& dest,
                  vector<vector<bool>>& visited,
                  int& pathCount)
{
    if (r == dest.first && c == dest.second) {
        pathCount++;
        return;
    }

    visited[r][c] = true;

    int N = maze.size();

    if (isSafe(r, c, N) && maze[r][c] == 1) {

        if (r + 1 < N && !visited[r + 1][c])
            explorePaths(maze, r + 1, c, dest, visited, pathCount);

        if (r - 1 >= 0 && !visited[r - 1][c])
            explorePaths(maze, r - 1, c, dest, visited, pathCount);

        if (c + 1 < N && !visited[r][c + 1])
            explorePaths(maze, r, c + 1, dest, visited, pathCount);

        if (c - 1 >= 0 && !visited[r][c - 1])
            explorePaths(maze, r, c - 1, dest, visited, pathCount);
    }

    visited[r][c] = false;
}


int countUniquePaths(const vector<vector<int>>& maze,
                     pair<int, int>& start,
                     pair<int, int>& end)
{
    int N = maze.size();

    if (N == 0 || maze[start.first][start.second] == 0 ||
        maze[end.first][end.second] == 0)
        return 0;

    int pathCount = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    explorePaths(maze, start.first, start.second, end, visited, pathCount);

    return pathCount;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> end = {3, 3};

    cout << "Total number of unique paths: "
         << countUniquePaths(maze, start, end) << endl;

    return 0;
}
