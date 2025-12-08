void GetcombinationSum(vector<int>& candidates, vector<int>& ans, vector<vector<int>>&      combinationSum, int target, int i) 
    {
        if(target == 0)
        {
            combinationSum.push_back({ans});
            return;
        }
        if(i>=candidates.size()||target<0){
            return;
        }
        
        ans.push_back(candidates[i]);
        GetcombinationSum(candidates, ans, combinationSum, target - candidates[i], i);
        
        ans.pop_back();
        
        GetcombinationSum(candidates, ans, combinationSum, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> combinationSum;
        int i;
        GetcombinationSum(candidates, ans, combinationSum, target, 0);
        return combinationSum;

    }
