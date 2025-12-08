void helperrec(int n, vector<int>& arr, int k, int i,vector<vector<int>>& result, vector<int>& ans){
        if(ans.size()==k){
            result.push_back({ans});
            return;
        }
        if(i>=arr.size()){
            return;
        }
        ans.push_back(arr[i]);
        helperrec(n,arr,k,i+1,result,ans);
        ans.pop_back();
        helperrec(n,arr,k,i+1,result,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++) arr.push_back(i);
        vector<int> ans;

        vector<vector<int>> result;
        helperrec(n,arr,k,0,result,ans);
        return result;
    }
