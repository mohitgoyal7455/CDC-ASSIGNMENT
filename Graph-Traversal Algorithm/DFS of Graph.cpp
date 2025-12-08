class Solution {
  private:
    void dfsHelper(vector<vector<int>>& adj,int node , vector<int>& visited , vector<int>& result){
        visited[node] = 1;
        result.push_back(node);
        
        for(int num : adj[node]){
            if(!visited[num]){
                dfsHelper(adj,num,visited,result);
            }
        }
        
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> visited(n,0);
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsHelper(adj,i, visited, result);
            }
        }

        return result;
    }
};