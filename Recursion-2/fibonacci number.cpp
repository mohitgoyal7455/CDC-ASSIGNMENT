class Solution {
  public:
    int fibonacci(int x, vector<int> &dp) {
        // Base cases
        if (x == 0) return 0;
        if (x == 1) return 1;
        
        
        if (dp[x] != -1)
            return dp[x];
        
        return dp[x] = fibonacci(x - 1, dp) + fibonacci(x - 2, dp);
    }
    
    int nthFibonacci(int n) {
        vector<int> dp(n + 1, -1); 
        return fibonacci(n, dp);
    }
};
