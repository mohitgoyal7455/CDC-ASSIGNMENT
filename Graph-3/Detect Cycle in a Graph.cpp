class Solution {
  private:
    bool dfs(vector<vector<int>>& adj,vector<int> &visited, vector<int> &path, int start){
        visited[start] = 1;
        path[start] = 1;
        
        for(auto node:adj[start]){
            if(!visited[node]){
                if(dfs(adj,visited,path,node)) return true;
            }else if(path[node]){
                return true;
            }
        }
        
        path[start] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> visited(V,0);
        vector<int> path(V,0);
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);  
        }
        
        for(int i = 0 ; i < V ; i++){
            if(dfs(adj,visited,path,i)) return true;
        }
        
        return false;
    }
};