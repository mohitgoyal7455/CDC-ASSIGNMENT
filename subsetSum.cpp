class Solution {
public:
   
    bool findSubsets(int idx, int n, vector<int>& arr, int target) {
        if (target == 0) return true;
        if (idx == n) return false;

        if (arr[idx] <= target && findSubsets(idx + 1, n, arr, target - arr[idx])) 
            return true;

        return findSubsets(idx + 1, n, arr, target);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        return findSubsets(0, arr.size(), arr, sum);
    }
};
