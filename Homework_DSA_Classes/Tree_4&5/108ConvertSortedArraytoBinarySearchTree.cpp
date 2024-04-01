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
    TreeNode* solve(vector<int>& nums,int i ,int j){
        if(i>j){
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[(i+(j-i)/2)]);
        root->left = solve(nums,i,(i+(j-i)/2)-1);
        root->right = solve(nums,(i+(j-i)/2)+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,n-1);
    }

};