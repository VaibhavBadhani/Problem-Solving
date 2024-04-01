
class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root==NULL)return NULL;
        //p&q check
        if(root->data==p)return root;
        if(root->data==q)return root;
        //not foun d
        Node* lans= lowestCommonAncestor(root->left,p,q);
        Node* rans= lowestCommonAncestor(root->right,p,q);
        //check
        if(lans==NULL&&rans==NULL)return NULL;
        if(lans!=NULL&&rans==NULL)return lans;
        if(lans==NULL&&rans!=NULL)return rans;
        else
        return root;

    }
    int height(Node* root,int x){
        if(!root) return 1e9;
        if(root->data==x) return 0;
        int lh = height(root->left,x);
        int rh = height(root->right,x);
        return 1+min(lh,rh);
    }
    int findDist(Node* root, int a, int b) {
        Node* lca = lowestCommonAncestor(root,a,b);
        int h1 = height(lca,a);
        int h2 = height(lca,b);
        return h1+h2;
    }
};