class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int col = m - 1; col >= 0; col--) {
            for (int row = 0; row < n; row++) {
                int right = (col == m - 1) ? 0 : dp[row][col + 1];
                int right_up = (row == 0 || col == m - 1) ? 0 : dp[row - 1][col + 1];
                int right_down = (row == n - 1 || col == m - 1) ? 0 : dp[row + 1][col + 1];
                
                dp[row][col] = mat[row][col] + max({right, right_up, right_down});
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, dp[i][0]);
        return res;
    }
};
