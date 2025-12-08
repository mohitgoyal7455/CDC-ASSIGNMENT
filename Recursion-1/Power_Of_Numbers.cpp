class Solution {
  public:
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int power(int base, int exp) {
        if (exp == 0)
            return 1;

        int half = power(base, exp / 2);

        if (exp % 2 == 0)
            return half * half;       
        else
            return base * half * half; 
    }

    int reverseExponentiation(int n) {
        int exp = reverseNum(n);
        return power(n,exp);
    }
};