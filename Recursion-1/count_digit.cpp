class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int num = n;
        int count = 0;
        while(n){
            int digit = n%10;
            n = n/10;
            
            if(digit==0){
                continue;
            }
            
            if(num%digit == 0){
                count++;
            }
            
        }
        
        return count;
    }
};