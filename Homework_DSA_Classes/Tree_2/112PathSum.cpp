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
    bool solve(TreeNode* root, int targetSum,int sum){
        if(!root) return false;
        if(!root->left&&!root->right){
            sum+=root->val;
            return targetSum==sum;
        } 
        bool a= false;
        if(root->left) a=solve(root->left,targetSum,root->val+sum);
         bool b= false;
        if(root->right) b=solve(root->right,targetSum,root->val+sum);
        return a||b;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
         return solve(root,targetSum,sum);
    }
};