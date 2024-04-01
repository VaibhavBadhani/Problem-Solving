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
    bool solve(TreeNode* root,long long lowb,long long highb){
        if(root==NULL) return true;
        if((root->val<highb&&root->val>lowb)&&solve(root->left,lowb,root->val)&&solve(root->right,root->val,highb)){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long lowb = LONG_MIN;
        long long highb = LONG_MAX;
        return solve(root,lowb,highb);
    }
};




