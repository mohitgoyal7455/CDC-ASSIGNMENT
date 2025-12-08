class Solution {
public:
    bool isValid(string s) {
         stack<char> stk;
        unordered_map<char, char> matching = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char ch : s) {
            if (matching.count(ch)) {
                if (!stk.empty() && stk.top() == matching[ch]) {
                    stk.pop(); 
                } else {
                    return false; 
                }
            } else {
                stk.push(ch);
            }
        }

        return stk.empty();
    }
};