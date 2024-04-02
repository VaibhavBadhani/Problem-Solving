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
 
class nodev{
    public:
    int maxnode,minnode,maxsize;
    nodev(int minnode,int maxnode,int maxsize){
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->maxsize = maxsize;
    }
};
class Solution {
    int ab = INT_MIN;
public:
    nodev solve(TreeNode* root){
        if(!root) return nodev(INT_MAX,INT_MIN,0);
        nodev l = solve(root->left);
        nodev r = solve(root->right);
        int val = root->val;
        if(l.maxnode<root->val&&root->val<r.minnode){
            ab= max(ab,l.maxsize+r.maxsize+root->val);
            return nodev(min(root->val,l.minnode),max(root->val,r.maxnode),l.maxsize+r.maxsize+root->val);
        }
        return nodev(INT_MIN,INT_MAX,0);
        
    }
    int maxSumBST(TreeNode* root) {
        int ans = solve(root).maxsize;
        return ab>0?ab:0;
        
    }
};
