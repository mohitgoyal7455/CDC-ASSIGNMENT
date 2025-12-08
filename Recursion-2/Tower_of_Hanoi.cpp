class Solution {
  public:
    long long moves = 0;
    void solve(int n, int from, int to, int aux) {
        if (n == 1) {
            moves++;
            return;
        }

        solve(n - 1, from, aux, to);
        moves++;

        solve(n - 1, aux, to, from);
    }
    
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        solve(n, from, to, aux);
        return moves;
    }
};