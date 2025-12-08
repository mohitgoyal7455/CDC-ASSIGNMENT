#include <vector>
#include <stack>
using namespace std;

vector<int> Smallestonleft(int arr[], int n) {
    vector<int> res;
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        
        if (st.empty())
            res.push_back(-1);
        else
            res.push_back(st.top());
        
        st.push(arr[i]);
    }
    
    return res;
}
