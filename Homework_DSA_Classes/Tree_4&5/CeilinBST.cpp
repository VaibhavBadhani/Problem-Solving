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
int better(Node* root, int input){
    if (root == NULL) return -1;
    if(root->data== input) return input;
    if(root->data<input){
        return better(root->right,input);
    }
    int val = better(root->left, input);
    return (val >= input) ? val : root->data;
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    // int val =-1;
    // find(root,input,val); 
    // return val;
    return better(root,input);
}