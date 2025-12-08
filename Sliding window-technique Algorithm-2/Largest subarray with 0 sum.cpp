class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int,int> mp;
        int sum = 0, maxLen = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == 0) maxLen = i + 1;
            if(mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
