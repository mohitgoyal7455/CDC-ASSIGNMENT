void helperrec(vector<string>& result, string current, int open, int close, int n){
        if(current.size() == 2*n){
            result.push_back({current});
            return;
        }
        if(open<n){
            helperrec(result,current+'(',open + 1, close,n);
        }
        if(close<open){
            helperrec(result,current+')',open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        int open = 0 ;
        int close = 0;
        helperrec(result,current,open,close,n);
        return result;
    }
