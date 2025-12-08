bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return p == q;
        }
        
        bool lefsub = isSameTree(p->left,q->left);
        bool rightsub = isSameTree(p->right,q->right);
        return lefsub && rightsub && p->val == q->val;
}
