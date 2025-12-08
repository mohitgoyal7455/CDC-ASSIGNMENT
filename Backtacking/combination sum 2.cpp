void GetcombinationSum(vector<int>& candidates, vector<int>& ans, vector<vector<int>>& combinationSum2, int target, int i) 
{
    if(target == 0)
    {
        combinationSum2.push_back(ans);
        return;
    }
    if(i >= candidates.size() || target < 0)
        return;

    // pick current element
    ans.push_back(candidates[i]);
    GetcombinationSum(candidates, ans, combinationSum2, target - candidates[i], i + 1);
    ans.pop_back();

    // skip duplicates
    int j = i + 1;
    while(j < candidates.size() && candidates[j] == candidates[i])
        j++;

    GetcombinationSum(candidates, ans, combinationSum2, target, j);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> ans;
    vector<vector<int>> combinationSum2;
    sort(candidates.begin(), candidates.end());
    GetcombinationSum(candidates, ans, combinationSum2, target, 0);
    return combinationSum2;
}
