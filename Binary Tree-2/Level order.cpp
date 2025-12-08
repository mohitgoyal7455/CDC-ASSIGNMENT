void levelordertraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
       Node* curr = q.front();
       q.pop();

       cout << curr -> data;
       if(curr == NULL)
       {
            if(!q.empty()){
                q.push(NULL);
                cout << endl;
                continue;
            }
            else{
                break;
            }
        }
       if(curr->left!=NULL){
            q.push(curr->left);
       }
       if(curr->right!=NULL){
            q.push(curr->right);
       }
        cout << endl;
       
    }
}
