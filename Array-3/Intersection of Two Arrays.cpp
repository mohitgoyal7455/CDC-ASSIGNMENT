class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        for(int i : nums1){
            freq[i]++;
        }

        vector<int> result;

        for(int i : nums2){
            if(freq[i]>=1){
                result.push_back(i);
                freq.erase(i);
            }
        }


        return result;
    }
};