class Solution {
public:
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited) {
        return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && visited[x][y] == 0);
    }

    void solve(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited, string path, vector<string> &result) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        visited[x][y] = 1;

        
        if (isSafe(x + 1, y, n, maze, visited))
            solve(x + 1, y, n, maze, visited, path + 'D', result);

        
        if (isSafe(x, y - 1, n, maze, visited))
            solve(x, y - 1, n, maze, visited, path + 'L', result);

        
        if (isSafe(x, y + 1, n, maze, visited))
            solve(x, y + 1, n, maze, visited, path + 'R', result);

        
        if (isSafe(x - 1, y, n, maze, visited))
            solve(x - 1, y, n, maze, visited, path + 'U', result);

        visited[x][y] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze) {
        int n = maze.size();
        vector<string> result;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(0, 0, n, maze, visited, "", result);

        sort(result.begin(), result.end());
        return result;
    }
};