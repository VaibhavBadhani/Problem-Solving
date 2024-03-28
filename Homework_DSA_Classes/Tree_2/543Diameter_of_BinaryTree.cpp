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
 int maxDepth(TreeNode* root) {
           // Base Condition
        if(root == NULL) return 0;
        // Hypothesis
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        // Induction
        return max(left, right) + 1; 
    }
     int ans(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int lh = ans(root->left,maxi);
        int rh = ans(root->right,maxi);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==NULL)return 0;
        // int op1 =diameterOfBinaryTree(root->left);
        // int op2 =diameterOfBinaryTree(root->right);
        // int op3 = maxDepth(root->left)+maxDepth(root->right);
        // return max(op1,max(op2,op3));
        if(root==NULL) return 0;
        int maxi=0;
        ans(root,maxi);
        return maxi;
    }
};