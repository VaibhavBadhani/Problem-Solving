/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fillmapi( map<int ,int>&mapi,vector<int>&inorder,int size )
    {
    for(int i=0;i<size;i ++)
     {mapi[inorder[i]]=i;
     }
    }
     TreeNode* solve( vector<int>&preorder, vector<int>&inorder,int &preindex,int startinorder,int endinorder,int size,map<int,int>&mapi)
    {
        //base 
        if(preindex>=size||startinorder>endinorder){return NULL;}
        //solve omne 
        int element = preorder[preindex++];
        TreeNode* root = new TreeNode(element);
        int pos = mapi[element];
        //recursion
        root-> left =solve(preorder,inorder,preindex,startinorder,pos-1,size,mapi);
        root-> right =solve(preorder,inorder,preindex,pos+1,endinorder,size,mapi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        TreeNode* ans;
        int size = preorder.size();
        map<int , int> mapi;
        fillmapi(mapi,inorder,size);  
        int preindex =0;    
        return solve(preorder,inorder,preindex,0,size-1,size,mapi);
    }
};


TreeNode* trr(int& i,vector<int>& p,int b){
        if(i==p.size()||b<p[i]) return NULL;
        TreeNode* node = new TreeNode(p[i]);
        i++;
        node->left = trr(i,p,node->val);
        node->right = trr(i,p,b);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return trr(i,preorder,INT_MAX);
    }
};