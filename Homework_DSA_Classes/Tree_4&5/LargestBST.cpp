class nodev{
    public:
    int maxnode,minnode,maxsize;
    nodev(int minnode,int maxnode,int maxsize){
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->maxsize = maxsize;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    nodev solve(Node* root){
        if(!root) return nodev(INT_MAX,INT_MIN,0);
        nodev l = solve(root->left);
        nodev r = solve(root->right);
        if(l.maxnode<root->data&&root->data<r.minnode){
            return nodev(min(root->data,l.minnode),max(root->data,r.maxnode),l.maxsize+r.maxsize+1);
        }
        
            return nodev(INT_MIN,INT_MAX,max(l.maxsize,r.maxsize));
        
    }
    int largestBst(Node *root)
    {
    	return solve(root).maxsize;
    }
};