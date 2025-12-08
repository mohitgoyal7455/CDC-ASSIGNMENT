class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<pair<double,int>> v;
        int n = val.size();
        
        for (int i = 0; i < n; i++) {
            v.push_back({(double)val[i] / wt[i], i});
        }
        
        sort(v.rbegin(), v.rend());
        
        int total = 0;
        
        for (auto &p : v) {
            int i = p.second;
            if (wt[i] <= W) {
                W -= wt[i];
                total += val[i];
            }
        }
        
        return total;
    }
};
