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
    // void solve(TreeNode* root, int low, int high,int& sum){
    //     if(root==NULL) return;
    //     if(root->val>=low&&root->val<=high){
    //         sum+=root->val;
    //     }
    //     if(root->left){
    //         solve(root->left,low,high,sum);
    //     }
    //     if(root->right){
    //         solve(root->right,low,high,sum);
    //     }
    //     return;
    // }
    int bet(TreeNode* root, int low, int high){
        if(!root) return 0;
        int ls = bet(root->left,low,high);
        int rs = bet(root->right,low,high);
        if(root->val>=low&&root->val<=high){
            return ls+rs+root->val;
        }
        return ls+rs;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        // solve(root,low,high,sum);
        return bet(root,low,high);
    }
};