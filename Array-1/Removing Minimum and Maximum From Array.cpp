class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        unordered_map<int,int> index;
        for(int i = 0 ; i < nums.size() ; i++){
            index[nums[i]] = i;
        }

        sort(nums.begin(),nums.end());
        int maxi = nums.back();
        int mini  = nums.front();

        int n = nums.size();

        int both_front = max(index[mini],index[maxi])+1;
        int both_back = n - min(index[mini],index[maxi]);
        int diff = -1;
        if(index[maxi]>index[mini]){
            diff = (index[mini]+1) + (n - index[maxi]);
        }else{
            diff = (index[maxi]+1) + (n - index[mini]);
        }

        return min({both_front,both_back,diff});
    }
};