void find(Node* root, int k,int& val){
    
    if(root->data==k) {
        val =k;
        return;
    }
    if(root->data>k){
        val= root->data;
        if(root->left)
        find(root->left,k,val);
    }
    else{
        if(root->right)
        find(root->right,k,val);
    }
    return ;
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int val =-1;
    find(root,input,val); 
    return val;
}