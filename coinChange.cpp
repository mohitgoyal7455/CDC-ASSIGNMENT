class Solution {
  public:
   
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= sum; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[sum];
    }
};
