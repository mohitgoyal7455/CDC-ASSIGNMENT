class Solution {
  public:
    void print(int i,int n){
        cout << i << " ";
        
        if(i==n){
            return;
        }
        
        print(i+1,n);
    }
    
    void printTillN(int n) {
        // code here
        int i = 1;
        print(i,n);
    }
};