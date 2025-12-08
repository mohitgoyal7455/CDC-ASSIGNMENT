TreeNode* build(int val,unordered_map<int,pair<int,int>>& child) 
    {
        if(val == -1){
            return nullptr;
        }
        TreeNode* root = new TreeNode(val);
        root -> left = build(child[val].first,child);
        root -> right = build(child[val].second,child);
        return root;

    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<int,int>> child;
        unordered_set<int> childset;
        child.reserve(descriptions.size() * 2); 
        childset.reserve(descriptions.size() * 2);

        for(auto&d : descriptions){
            int p = d[0];
            int c = d[1];
            int isleft = d[2];
            if (!child.count(p)) child[p] = {-1, -1};

            if(isleft == 1){
                child[p].first = c;
            }
            else{
                child[p].second = c;
            }
            childset.insert(c);
            if (!child.count(c)) child[c] = {-1, -1};
        }

        int rootval = -1;
        for(auto& d:descriptions){
            if(!childset.count(d[0])){
                rootval = d[0];
                break;
            }
        }
        return build(rootval,child);
    }
