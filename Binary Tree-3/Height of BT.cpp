int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);
        return max(leftdepth,rightdepth) + 1;
    }
