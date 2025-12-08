class Solution {
public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int,int> mp;
        int sum = 0, count = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == 0) count++;
            if(mp.find(sum) != mp.end()) count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};
