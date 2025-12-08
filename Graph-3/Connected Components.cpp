class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                stack<int> st;
                st.push(i);
                visited[i] = true;
                
                while (!st.empty()) {
                    int node = st.top();
                    st.pop();
                    
                    for (int neigh : adj[node]) {
                        if (!visited[neigh]) {
                            visited[neigh] = true;
                            st.push(neigh);
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
