class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int plat = 0, result = 0;
        int n = arr.size();
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat++;
                result = max(result, plat);
                i++;
            } else {
                plat--;
                j++;
            }
        }
        
        return result;
    }
};
