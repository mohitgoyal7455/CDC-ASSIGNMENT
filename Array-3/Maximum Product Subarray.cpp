class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxProd = nums[0];
        long long minProd = nums[0];
        long long result = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            long long num = nums[i];
            
            if(num < 0) swap(maxProd, minProd);
            
            maxProd = max(num, maxProd * num);  
            minProd = min(num, minProd * num);  
            
            result = max(result, maxProd);     
        }
        
        return result;
    }
};
