void GetAllsubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets){
        if(i==nums.size()){
            allsubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        GetAllsubsets(nums, ans, i+1, allsubsets);
        ans.pop_back();
        GetAllsubsets(nums, ans, i+1, allsubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;
        GetAllsubsets(nums, ans, 0, allsubsets);
        return allsubsets;
    }
