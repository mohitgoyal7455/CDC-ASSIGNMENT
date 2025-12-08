class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        function<bool(int,int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m)
                return false;
            if (grid[i][j] == 1)
                return true;
            
            grid[i][j] = 1;
            
            bool up = dfs(i - 1, j);
            bool down = dfs(i + 1, j);
            bool left = dfs(i, j - 1);
            bool right = dfs(i, j + 1);
            
            return up && down && left && right;
        };
        
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j)) count++;
                }
            }
        }
        
        return count;
    }
};
