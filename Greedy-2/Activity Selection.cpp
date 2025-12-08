class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int,int>> v;
        for (int i = 0; i < start.size(); i++) {
            v.push_back({finish[i], start[i]});
        }
        sort(v.begin(), v.end());
        
        int count = 1;
        int lastFinish = v[0].first;
        
        for (int i = 1; i < v.size(); i++) {
            if (v[i].second > lastFinish) {
                count++;
                lastFinish = v[i].first;
            }
        }
        
        return count;
    }
};
