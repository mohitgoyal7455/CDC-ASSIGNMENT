class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> result;
        
        queue<int> q;
        
        
        visited[0] = 1;
        q.push(0);
        
        
        while(!q.empty()){
            for(int num:adj[q.front()]){
                if(!visited[num]){
                    q.push(num);
                    visited[num] = 1;
                }
            }
            
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};