class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int pixel = image[sr][sc];
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            int drow[4] = {1,0,-1,0};
            int dcol[4] = {0,1,0,-1};

            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >=0 && nrow < n && ncol < m && !vis[nrow][ncol] && image[nrow][ncol]==pixel){
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

        return image;
    }
};