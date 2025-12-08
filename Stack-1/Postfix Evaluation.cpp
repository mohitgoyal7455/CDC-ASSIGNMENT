#include <vector>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;

        for (string token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = 0;
                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = a * b;
                else if (token == "/") res = a / b;  
                else if (token == "^") res = pow(a, b);
                st.push(res);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
